import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;


public class CSVStreamer {

    private final String filePath;

    /*
    Files.lines(Paths.get(filePath))
            .skip(1)
                    .map(line -> line.split(","))
    */

    public CSVStreamer(String csvFileName, Integer queryID) {
        filePath = csvFileName;

        switch (queryID) {
            // 1. Total quantity of products purchased by customers whose names start with 'A'
            case 1 -> {
                int[] arrOfColumns = {4, 6, 8, 10, 12};

                try {
                    long result = Files.lines(Paths.get(filePath))
                            .skip(1) // Skip the header
                            .map(line -> line.split(",")) // Split each line into an array of columns
                            .filter(rows -> {

                                long cnt = Arrays.stream(arrOfColumns)
                                        .filter(index -> !rows[index].isEmpty() && rows[0].charAt(0) == 'B')
                                        .count();
                                return cnt > 0;

                            }) // Filter customers whose names start with 'A'
                            .mapToInt(rows -> Arrays.stream(arrOfColumns) // Process specified columns
                                    .filter(index -> index < rows.length && !rows[index].isEmpty()) // Ensure valid index and non-empty value
                                    .map(index -> Integer.parseInt(rows[index])) // Parse column value to int
                                    .sum()) // Sum values from the specified columns for this row
                            .sum(); // Sum up the totals for all matching rows

                    System.out.println(result);
                } catch (Exception e) {
                    e.printStackTrace(); // Print detailed stack trace for debugging
                }
            }



            // 2. Most expensive product sold
            case 2 -> {
                int[] arrOfPriceColumns = {3, 5, 7, 9, 11};

                try {
                    // Read the header row to map column indices to names
                    String headerLine = Files.lines(Paths.get(filePath)).findFirst().orElseThrow(() -> new IllegalArgumentException("File is empty!"));
                    String[] header = headerLine.split(",");

                    // Process the stream to find the max ratio and its corresponding column name
                    String result = Files.lines(Paths.get(filePath))
                            .skip(1) // Skip the header row
                            .flatMap(line -> {
                                String[] row = line.split(",");
                                return Arrays.stream(arrOfPriceColumns)
                                        .filter(index -> index < row.length - 1 && !row[index].isEmpty() && !row[index + 1].isEmpty()) // Ensure indices and values are valid
                                        .mapToObj(index -> new Object[]{
                                                Double.parseDouble(row[index]) / Double.parseDouble(row[index + 1]), // Calculate ratio
                                                header[index] // Map to column name
                                        });
                            })
                            .max((a, b) -> Double.compare((double) a[0], (double) b[0])) // Find the max ratio
                            .map(max -> (String) max[1]) // Extract the column name
                            .orElse("No valid data");

                    // Output the result
                    System.out.println("Column with the max price-to-amount ratio: " + result);

                } catch (Exception e) {
                    e.printStackTrace(); // Print detailed stack trace for debugging
                }
            }
            // 3. Date of the highest-paid purchase by a customer


            // 4. Most popular product before 2000

            // 5. Least popular product after and including 2000


        }
    }
}
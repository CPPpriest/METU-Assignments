

public class Main {
    public static void main(String[] args) {

        if (args.length != 2) {
            System.err.println("Usage: java YourProgramName csv_file_name question_no");
            return;
        }

        String csvFileName = args[0];
        String questionNo = args[1];

        CSVStreamer streamerObj = new CSVStreamer(csvFileName, Integer.parseInt(questionNo) );
    }
}
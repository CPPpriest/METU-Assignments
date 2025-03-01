import java.io.IOException;
import java.util.ArrayList;

import java.io.BufferedReader;
import java.io.FileReader;


import java.io.InputStreamReader;


public class CengTreeParser
{
    public static ArrayList<CengBook> parseBooksFromFile(String filename)
    {
        ArrayList<CengBook> retArray = new ArrayList<CengBook>();
        try(BufferedReader BK = new BufferedReader( new FileReader(filename) ) )
        {

            String RL = BK.readLine();

            while ( RL != null)
            {
                //Split input string into fields
                String[] splitFieldStr = RL.split("\\|");

                //record created from the currLine
                CengBook newRecord =    new CengBook(   Integer.parseInt(splitFieldStr[0]),
                                                        splitFieldStr[1],
                                                        splitFieldStr[2],
                                                        splitFieldStr[3]    );

                //insert to ret
                retArray.add(newRecord);

                //next line
                RL = BK.readLine();
            }

        } catch (IOException e) { e.printStackTrace();}

        return retArray;
    }

    public static void startParsingCommandLine() throws IOException
    {
        BufferedReader BF = new BufferedReader(new InputStreamReader(System.in));

        Boolean isValid = true;
        while (isValid) {
            String RL = BF.readLine();
            String[] splitFieldStr = RL.split("\\|");

            switch (splitFieldStr[0]) {
                case "add":
                    //start from 1, 0->func
                    CengBook newRecord = new CengBook(Integer.parseInt(splitFieldStr[1]),
                            splitFieldStr[2],
                            splitFieldStr[3],
                            splitFieldStr[4]);
                    //insert to rn
                    CengBookRunner.addBook(newRecord);
                    break;

                case "search":
                    int key = Integer.parseInt(splitFieldStr[1]);
                    CengBookRunner.searchBook(key);
                    break;

                case "print":
                    CengBookRunner.printTree();
                    break;

                default:
                    // QUIT -->> check if work after break
                    isValid = false;
            }
        }
    }

}

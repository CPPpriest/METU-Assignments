package streamexample;

import java.util.*;
import java.util.stream.*;
import java.io.*;
import java.util.function.*;

public class QueryOLP {
	public static void main(String[] args) throws FileNotFoundException {
		BufferedReader br= new BufferedReader(new InputStreamReader(new FileInputStream(new File("courses.csv"))));

		Function<String, Course> mapToCourse = (line) -> {
			String[] p = line.split(", ");
			return new Course(Integer.parseInt(p[0]), p[1], p[2], Integer.parseInt(p[3]), Double.parseDouble(p[4]), Double.parseDouble(p[5]), Integer.parseInt(p[6]));
		};
    
		List<Course> crs = br.lines().skip(1).map(mapToCourse).collect(Collectors.toList());

// Query 1: Codes of all the courses in sorted order 
		System.out.println("Query 1:"); 
		System.out.println( );
		System.out.println("--------"); 

// Query 2: Instructors (with no duplicates) teaching courses with price under USD 1 in sorted order 
		System.out.println("Query 2:"); 
		System.out.println( );
		System.out.println("--------"); 

// Query 3: Price of the cheapest course 
		System.out.println("Query 3:"); 
		System.out.println( );
		System.out.println("--------"); 

// Query 4: Instructor of the cheapest course  
		System.out.println("Query 4:"); 
		System.out.println( );
		System.out.println("--------"); 

// Query 5: Sum of the durations of the courses whose number of trainees are above the average 
		System.out.println("Query 5:"); 
		System.out.println( );
		System.out.println("--------"); 

	}
}

import java.util.*;
import java.io.*;

class Main{
	public static void main(String[]args){
		try{
			Scanner in = new Scanner(new File("team.in"));	
			PrintWriter out = new PrintWriter("team.out");
			// Scanner in = new Scanner(System.in);
			int [][] arr = new int[3][3];
			for(int i = 0; i < 3; i++){
				String [] items = in.nextLine().split(" ");
				for(int j = 0; j < 3; j++){
					arr[i][j] = Integer.parseInt(items[j]);
				}
			}
			double max = Double.MIN_VALUE;
			for(int i = 0; i < 3; i++){
				double sum = 0;
				for(int j = 0; j < 3; j++){
					sum += Math.pow(arr[j][i],2);
				}
				max = Math.max(max, Math.sqrt(sum));
			}
			// System.out.println(max);
			out.println(max);
			in.close();
			out.close();
		}catch(Exception e){}
	}
}

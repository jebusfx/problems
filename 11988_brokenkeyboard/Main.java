import java.io.*;
import java.util.*;

public class Main{
	public static void addSb(Boolean addLast, LinkedList<StringBuilder> result, StringBuilder sb){
		if(addLast)
			result.addLast(sb);
		else
			result.addFirst(sb);
	}
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		String line;
		while((line = br.readLine()) != null){
			LinkedList<StringBuilder> result = new LinkedList<>();
			StringBuilder sb = new StringBuilder();
			Boolean addLast = true;
			for(int i = 0; i<line.length(); i++){
				if(line.charAt(i) == '[' || line.charAt(i) == ']'){
					addSb(addLast, result, sb);
					addLast = line.charAt(i) == '[' ? false : true;
					sb = new StringBuilder();
				}
				else{
					sb.append(line.charAt(i));
				}
			}
			addSb(addLast, result, sb);
			result.forEach((c)->pw.print(c));
			pw.println();
			pw.flush();
		}
		pw.close();
	}
}

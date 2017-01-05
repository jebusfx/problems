import java.io.*;
import java.util.*;

public class Main{
	public static void main(String [] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int n = Integer.parseInt(br.readLine());
		String tree = br.readLine(); // read the blankline
		while(n-- > 0){
			Integer population = 0;
			TreeMap<String, Integer> trees = new TreeMap<>();
			while((tree = br.readLine()) != null && tree.trim().length() > 0){
				if(trees.get(tree) == null){
					trees.put(tree, 1);
				}else{
					Integer count = trees.get(tree);
					trees.put(tree, ++count);
				}
				population++;
			}
			Set<String> keys = trees.keySet();
			for(String key: keys){
				pw.printf("%s %.4f\n",key, ((float)trees.get(key)/population)*100);
			}
			if(n > 0)
				pw.println();
		}
		pw.close();
	}
}

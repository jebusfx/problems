/*input
1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
abc
*/
import java.io.*;
import java.util.*;

public class char_test{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		Map<Character, Integer> heights = new HashMap<>();
		char a = 'a';
		for(int i = 0; i < 26; i++){
			heights.put((char)(a + i), in.nextInt());
		}
		String word = in.next();
		int maxHeight = 0;
		for(int i = 0; i < word.length(); i++){
			maxHeight = Math.max(heights.get(word.charAt(i)), maxHeight);
		}
		System.out.println(maxHeight * word.length());
	}
}
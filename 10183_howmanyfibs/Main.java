import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

class Main{

	private static int MAXFIBOS = 481;	
	private static BigInteger[] fibos = new BigInteger[MAXFIBOS+1];
	
	static BigInteger fibonacci(int n) {
    	if (n == 0 || n == 1){
    		fibos[n] = BigInteger.ONE;
    		return BigInteger.ONE;
    	}
    	if(fibos[n] != null)
    		return fibos[n];    	
    	BigInteger v = fibonacci(n - 2).add(fibonacci(n - 1));    	
    	fibos[n] = v;    	
    	return v;
	}

	public static void main(String args[]){		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner scanner = new Scanner(br);
		BigInteger a,b;		
		int i,count;
		fibonacci(MAXFIBOS);
		while(true){			
			count = 0;
			a = new BigInteger(scanner.next());
			b = new BigInteger(scanner.next());				
			if(a.equals(BigInteger.ZERO) && b.equals(BigInteger.ZERO))
				break;				

			for(i = 1;i<MAXFIBOS;i++){
				if(fibos[i].compareTo(b) == 1)
					break;				
				if(fibos[i].compareTo(a) >= 0 && fibos[i].compareTo(b) <= 0)
					count++;																
			}
			System.out.println(count);			
		}		
	}	
}

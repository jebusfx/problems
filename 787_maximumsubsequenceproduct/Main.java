import java.util.*;
import java.io.*;
import java.lang.Math;
import java.math.BigInteger;

class Main
{
	public static void main(String [] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		while((line = br.readLine()) != null)
		{
			int [] arr = Arrays.asList(line.split(" ")).stream()
			                                           .mapToInt(num -> Integer.parseInt(num))
			                                           .filter(num -> num != -999999).toArray();
			BigInteger max = new BigInteger(String.valueOf(Integer.MIN_VALUE));
			BigInteger [] results = new BigInteger[arr.length];
			BigInteger prod;
			for(int i = 0; i < arr.length; i++)
			{
				prod = BigInteger.ONE;
				for(int j = i; j < arr.length; j++)
				{
					prod = prod.multiply(new BigInteger(String.valueOf(arr[j])));
					if(results[j] == null)
						results[j] = new BigInteger(String.valueOf(Integer.MIN_VALUE));
					results[j] = results[j].max(prod);
					max = max.max(results[j]);
				}
			}
			System.out.println(max);
		}
	}
}

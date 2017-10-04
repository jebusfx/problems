import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {
    
    // public static BigInteger solve(BigInteger n)
    // {
    //     // number of trees that can be made with n vertices
    //     // same as a catalan number
    //     if(n.compareTo(BigInteger.ONE) == 0 || n.compareTo(BigInteger.ONE) < 0)
    //     {
    //         return BigInteger.ONE;
    //     }
    //     else
    //     {
    //         BigInteger sum = BigInteger.ZERO;
    //         for(int i = 1; BigInteger.valueOf(i).compareTo(n) < 0 || BigInteger.valueOf(i).compareTo(n) == 0; i++)
    //         {
    //             BigInteger myI = BigInteger.valueOf(i);
    //             BigInteger left = solve(myI.subtract(BigInteger.ONE));
    //             BigInteger right = solve(n.subtract(myI));
    //             sum = sum.add(left.multiply(right));
    //         }
    //         return sum;
    //     }
    // }
    public static Map<Integer, BigInteger> cache = new HashMap();
    public static BigInteger fact(int n)
    {
        BigInteger res = BigInteger.ONE;
        cache.put(1, res);
        for(int i = 2; i<=n; i++)
        {
            res = res.multiply(BigInteger.valueOf(i));
            cache.put(i, res);
        }
        return res;
    }

    public static void main(String args[] ) throws Exception 
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        BigInteger maxFact = fact(600);
        while(!(line = br.readLine()).equals("0"))
        {
            int n = Integer.parseInt(line);
            BigInteger catalan = cache.get(2*n).divide(cache.get(n + 1).multiply(cache.get(n)));
            System.out.println(catalan.multiply(cache.get(n)));
        }
    }
}

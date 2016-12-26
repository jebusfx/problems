import java.util.*;
import java.io.*;

public class Main{
	static class FastScanner {
        static BufferedReader br;
        static StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }
        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    static FastScanner newInput() throws IOException {
        if (System.getProperty("JUDGE") != null) {
            return new FastScanner(new File("kenobi.in"));
        } else {
            return new FastScanner(System.in);
        }
    }
    static PrintWriter newOutput() throws IOException {
        if (System.getProperty("JUDGE") != null) {
            return new PrintWriter("kenobi.out");
        } else {
            return new PrintWriter(System.out);
        }
    }

	public static void main(String[]args) throws IOException{
		try(PrintWriter out = newOutput()){
			FastScanner in = newInput();
			Deque dq = new LinkedList<>();
			int n = in.nextInt();
			while((n--) > 0){
				String op = in.next();
				switch(op){
					case "add":
						dq.addLast(in.nextInt());
						break;
					case "take":
						dq.pollLast();
						break;
					case "mum!":
						int half = dq.size()/2;
						while((half--) > 0){
							dq.addLast(dq.pollFirst());
						}
						break;
					default:
						break;
				}
			}
			out.println(dq.size());
			Iterator it = dq.iterator();
			StringJoiner sj = new StringJoiner(" ");
			while(it.hasNext()){
				sj.add(String.valueOf(it.next()));
			}
			out.println(sj.toString());
			out.close();
		}
	}
}

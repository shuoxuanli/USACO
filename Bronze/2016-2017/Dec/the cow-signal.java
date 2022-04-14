import java.util.*;
import java.io.*;

class Main {
  public static void main(String[] args) throws IOException{
    Kattio io = new Kattio("cowsignal"); 
    int M = io.nextInt();
    int N = io.nextInt();
    int K = io.nextInt();

  for(int i = 0; i < M; i++) {
    String str = io.next();
    for(int j = 0; j < K; j++) {
      for(int k = 0; k < N; k++) {
        for(int l = 0; l < K; l++) {
          io.print(str.charAt(k));
        }
      }
      io.println();
    }
  }
  io.close();


  }
  static class Kattio extends PrintWriter {
		private BufferedReader r;
		private StringTokenizer st;
	
		// standard input
		public Kattio() { this(System.in, System.out); }
		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}
		// USACO-style file input
		public Kattio(String problemName) throws IOException {
			super(new FileWriter(problemName + ".out"));
			r = new BufferedReader(new FileReader(problemName + ".in"));
		}
	
		// returns null if no more input
		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) { }
			return null;
		}
	
		public int nextInt() { return Integer.parseInt(next()); }
		public double nextDouble() { return Double.parseDouble(next()); }
		public long nextLong() { return Long.parseLong(next()); }
	}
}
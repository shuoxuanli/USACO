import java.util.*;
import java.io.*;

class Main {
  public static void main(String[] args) throws IOException{
    Kattio io = new Kattio("blocks");
    int N = io.nextInt();
    int[] freqs = new int[26];

    for(int i = 0; i < N; i++) {
      String front = io.next();
      String back = io.next();
      int[] freqs1 = new int[26];
      int[] freqs2 = new int[26];
      for(int j = 0; j < front.length(); j++) {
        freqs1[front.charAt(j) - 97]++;
      }

      for(int j = 0; j < back.length(); j++) {
        freqs2[back.charAt(j) - 97]++;
      }

      for(int j = 0; j < 26; j++) {
        freqs[j] += Math.max(freqs1[j], freqs2[j]);
      }
    }
    
    for(int i = 0; i < 26; i++) {
      io.println(freqs[i]);
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

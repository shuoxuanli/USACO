import java.util.*;
import java.io.*;
class Main {
  public static void main(String[] args) throws IOException {
    Kattio io = new Kattio("mixmilk");
    
    int[] amount = new int[3];
    int[] capacity = new int[3];

    for(int i = 0 ; i < 3; i++){
      capacity[i] = io.nextInt();
      amount[i] = io.nextInt();
    }

    for(int i = 0; i < 100; i++) {
      if (capacity[(i+1)%3] >= amount[i%3] + amount[(i+1)%3]) {
        amount[(i+1)%3] += amount[i%3];
        amount[i%3] = 0;
      }
      else if (capacity[(i+1)%3] < amount[i%3] + amount[(i+1)%3]) {
        amount[i%3] -= capacity[(i+1)%3]- amount[(i+1)%3];
        amount[(i+1)%3] = capacity[(i+1)%3];
      }
    }
    
    for(int i = 0; i < amount.length; i++) {
      io.println(amount[i]);
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

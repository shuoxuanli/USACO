import java.util.*;
import java.io.*;
import java.util.Arrays;

class Main {
  public static void main(String[] args) throws IOException {
    Kattio io = new Kattio("speeding");
    int N = io.nextInt(); int M = io.nextInt();
    int[] segmentN = new int[N];
    int[] segmentM = new int[M];
    int[] speed = new int[M];
    int[] limit = new int[N];
    int[] speed100 = new int[100];
    int[] limit100 = new int[100];
    int[] sumN = new int[N];
    int[] sumM = new int[M];
    int max = 0;

    for(int i = 0; i < N; i++) {
      segmentN[i] = io.nextInt();
      limit[i] = io.nextInt();
    }

    for(int i = 0; i < M; i++) {
      segmentM[i] = io.nextInt();
      speed[i] = io.nextInt();
    }

    int s = 0;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < i+1; j++) {
        s += segmentN[j];
      }
      sumN[i] = s;
      s = 0;
    }

    int m = 0;
    for(int i = 0; i < M; i++) {
      for(int j = 0; j < i+1; j++) {
        m += segmentM[j];
      }
      sumM[i] = m;
      m = 0;
    }

    for(int i = 0; i < N-1; i++) {
      for(int j = sumN[i]; j < sumN[i+1]; j++) {
        limit100[j] = limit[i+1];
      }
    }

    for(int i = 0; i < segmentN[0]; i++) {
      limit100[i] = limit[0];
    }

    for(int i = 0; i < segmentM[0]; i++) {
      speed100[i] = speed[0];
    }

    for(int i = 0; i < M-1; i++) {
      for(int j = sumM[i]; j < sumM[i+1]; j++) {
        speed100[j] = speed[i+1];
      }
    }
    
    int maximum = 0;
    for(int i = 0; i < 100; i++) {
       if(speed100[i] - limit100[i] > maximum) {
         maximum = speed100[i] - limit100[i];
       }
    }

    io.println(maximum);
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

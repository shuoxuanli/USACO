import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws IOException {
		Kattio io = new Kattio("paint");
		int a = io.nextInt();
		int b = io.nextInt();
		int c = io.nextInt();
		int d = io.nextInt();

		int total = (b - a) + (d - c);
		int intersection = Math.max(Math.min(b, d) - Math.max(a, c), 0);
		int union = total - intersection;

		io.println(union);
		io.close();
	}

	static class Kattio extends PrintWriter {
		private BufferedReader r;
		private StringTokenizer st;

		public Kattio() { this(System.in, System.out); }
		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}

		public Kattio(String problemName) throws IOException {
			super(new FileWriter(problemName + ".out"));
			r = new BufferedReader(new FileReader(problemName + ".in"));
		}

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

import java.util.*;
import java.io.*;
class Main {
  public static void main(String[] args) throws IOException{
    Kattio io = new Kattio("square");
    int a1 = io.nextInt(); int a2 = io.nextInt();
    int a3 = io.nextInt(); int a4 = io.nextInt();
    int b1 = io.nextInt(); int b2 = io.nextInt();
    int b3 = io.nextInt(); int b4 = io.nextInt();

    int squareX1 = Math.min(a1, b1);
    int squareY1 = Math.min(a2, b2);
    int squareX2 = Math.max(a3, b3);
    int squareY2 = Math.max(a4, b4);

    int square = 0;
    if (squareX2 - squareX1 >= squareY2 - squareY1) {
      square = squareX2 - squareX1;
    }
    else if (squareX2 - squareX1 < squareY2 - squareY1) {
      square = squareY2 - squareY1;
    }

    io.println((int) Math.pow(square, 2));
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

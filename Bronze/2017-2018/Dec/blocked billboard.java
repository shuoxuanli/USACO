import java.util.*;
import java.io.*;

class Rect {
  int x1, x2, y1, y2;
  int area() {return (y2-y1)*(x2-x1);}
}

class Main {
  public static void main(String[] args) throws IOException{
    Kattio io = new Kattio("billboard");
    Rect a = new Rect(), b = new Rect(), c = new Rect();
    a.x1 = io.nextInt(); a.y1 = io.nextInt();
    a.x2 = io.nextInt(); a.y2 = io.nextInt();
    b.x1 = io.nextInt(); b.y1 = io.nextInt();
    b.x2 = io.nextInt(); b.y2 = io.nextInt();
    c.x1 = io.nextInt(); c.y1 = io.nextInt();
    c.x2 = io.nextInt(); c.y2 = io.nextInt();

    int visible = a.area() + b.area() - overlap(a,c) - overlap(b,c);

    io.println(visible);
    io.close();
  }

  static int overlap (Rect p, Rect q)  {
    int xOverlap = Math.max(0, Math.min(p.x2, q.x2) - Math.max(p.x1, q.x1));
    int yOverlap = Math.max(0, Math.min(p.y2, q.y2) - Math.max(p.y1, q.y1));
    return xOverlap*yOverlap;
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

import java.util.*;
import java.io.*;

class Main {
  public static void main(String[] args) throws IOException {
    Kattio io = new Kattio("shell");

    int N = io.nextInt();
    int [] shell = new int[3];
    int [] count = new int[3]; 

    for(int i = 0; i < shell.length; i++) {
      shell[i] = i;
    }

    for(int i = 0; i < N; i++) {
      int a = io.nextInt() - 1;
      int b = io.nextInt() - 1;
      int g = io.nextInt() - 1;

      int temp = shell[a];
      shell[a] = shell[b];
      shell[b] = temp;
       
      count[shell[g]]++;
    }

    io.println(Math.max(count[0], Math.max(count[1], count[2])));
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

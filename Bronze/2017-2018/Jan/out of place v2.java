import java.util.*;
import java.io.*;

class Main {
  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new FileReader("outofplace.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("outofplace.out")));

    int n = Integer.parseInt(in.readLine());

    int[] h = new int[n];
    for(int i = 0; i < n; i++) {
      StringTokenizer st = new StringTokenizer(in.readLine());
      h[i] = Integer.parseInt(st.nextToken());
    }

    int diff = 0;
    int[] h2 = new int[n];
    for(int i = 0; i < n; i++) {
      h2[i] = h[i];
    }
    Arrays.sort(h);

    for(int i = 0; i < n; i++) {
      if(h[i] != h2[i]) diff++;
    }

    out.println(diff-1);
    in.close();
    out.close();
  }
}

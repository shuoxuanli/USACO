import java.util.*;
import java.io.*;

class Main {
  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new FileReader("sleepy.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sleepy.out")));

    int n = Integer.parseInt(in.readLine());

    int[] order = new int[n];
    StringTokenizer st = new StringTokenizer(in.readLine());

    for(int i = 0; i < n; i++) {
      order[i] = Integer.parseInt(st.nextToken());
    }

    int count = 1;
    boolean sorted = false;
    for(int i = n-1; i > 0; i--) {
      if(order[i] > order[i-1]) {
        sorted = false;
        count++;
        continue;
      }
      break;
    }

    if(!sorted) out.println(n-count);
    else out.println(0);

    in.close();
    out.close();
  }
}

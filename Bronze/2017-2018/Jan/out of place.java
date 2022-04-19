import java.util.*;
import java.io.*;

class Main {

  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new FileReader("outofplace.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("outofplace.out")));

    int n = Integer.parseInt(in.readLine());
    int[] h1 = new int[n];
    int[] h2 = new int[n];
    for(int i = 0; i < n; i++) {
      StringTokenizer st = new StringTokenizer(in.readLine());
      h1[i] = Integer.parseInt(st.nextToken());
      h2[i] = h1[i];
    }
    int ans = swapFront(h1, n);
    if(!sorted(h1, n)) {
      ans = swapFront(h2, n);
    }

    out.println(ans);
    in.close();
    out.close();
  }

  static int[] swap(int[] h, int a, int b) {
    int temp = h[a];
    h[a] = h[b];
    h[b] = temp;
    return h;
  }

  static boolean sorted(int[] h, int n) {
    for(int i = 0; i < n - 1; i++) {
      if(h[i] > h[i+1]) {
        return false;
      }
    }
    return true;
  }

  static int swapFront(int[] h, int n) {
    int pos = n-1; 
    int swap = 0;
    while(pos > 0) {
      int current = pos;
      int pre = pos-1;
      if(h[current] < h[pre]) {
        while(h[pre] == h[pre-1] && pre > 0) {
          pre--;
        }
        swap(h, current, pre);
        swap++;
        pos = pre;
      }
      else pos--;
    }
    return swap;
  }

  static int swapBack(int[] h, int n) {
    int pos = 0; 
    int swap = 0;
    while(pos > 0) {
      int current = pos;
      int pre = pos+1;
      if(h[current] > h[pre]) {
        while(h[pre] == h[pre+1] && pre < n) {
          pre++;
        }
        swap(h, current, pre);
        swap++;
        pos = pre;
      }
      else pos++;
    }
    return swap;
  }
}

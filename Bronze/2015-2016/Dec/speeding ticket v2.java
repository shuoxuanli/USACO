import java.util.*;
import java.io.*;

class Main {
  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new FileReader("speeding.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("speeding.out")));

    StringTokenizer st = new StringTokenizer(in.readLine());
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    int[] miles = new int[100];
    int[] bessies = new int[100];

    int start = 0;
    for(int i = 0; i < n; i++) {
      st = new StringTokenizer(in.readLine());
      int segment = Integer.parseInt(st.nextToken());
      int speed = Integer.parseInt(st.nextToken());
      for(int j = start; j < start+segment; j++) {
        miles[j] = speed;
      }
      start += segment;
    }

    int bstart = 0;
    for(int i = 0; i < m; i++) {
      st = new StringTokenizer(in.readLine());
      int segment = Integer.parseInt(st.nextToken());
      int speed = Integer.parseInt(st.nextToken());
      for(int j = bstart; j < bstart+segment; j++) {
        bessies[j] = speed;
      }
      bstart += segment;
    }

    int diff = 0;
    for(int i = 0; i < 100; i++) {
      if(bessies[i] > miles[i]) {
        diff = Math.max(diff, bessies[i] - miles[i]);
      }
    }

    out.println(diff);
    in.close();
    out.close();
  }
}

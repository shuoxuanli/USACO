import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

class Main {
  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new FileReader("lifeguards.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lifeguards.out")));

    int n = Integer.parseInt(in.readLine());
    int[] timeline =  new int[1000];
    int[][] cow = new int[n][2];

    for(int i = 0; i < n; i++) {
      StringTokenizer st = new StringTokenizer(in.readLine());
      cow[i][0] = Integer.parseInt(st.nextToken());
      cow[i][1] = Integer.parseInt(st.nextToken());

      for(int j = cow[i][0]; j < cow[i][1]; j++) {
        timeline[j]++;
      }
    }

    int max = 0;
    
    for(int i = 0; i < n; i++) {
      int count = 0;
      for(int j = cow[i][0]; j < cow[i][1]; j++) {
        timeline[j]--;
      }

      for(int j = 0; j < timeline.length; j++) {
          if(timeline[j] != 0) count++;
      }

      for(int j = cow[i][0]; j < cow[i][1]; j++) {
        timeline[j]++;
      }
      max = Math.max(max, count);
    }

    out.println(max);
    in.close();
    out.close();
  }
}

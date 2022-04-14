import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("blist.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("blist.out")));
		
    int n = Integer.parseInt(in.readLine());

    int[] timeline = new int[1001];

    for(int i = 0; i < n; i++) {
      StringTokenizer st = new StringTokenizer(in.readLine());
      int from = Integer.parseInt(st.nextToken());
      int to = Integer.parseInt(st.nextToken());
      int bucket = Integer.parseInt(st.nextToken());

      for(int j = from; j <= to; j++) {
        timeline[j] += bucket;
      }
    }

    int max = Integer.MIN_VALUE;
    for(int i = 0; i < timeline.length; i++) {
      max = Math.max(max, timeline[i]);
    }
    
    out.println(max);
		in.close();
		out.close();
	}
}

import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(in.readLine());

    int n = Integer.parseInt(in.readLine());
		
    int[] flowers = new int[n];
    for (int i = 0; i < n; i++) {
      flowers[i] = Integer.parseInt(st.nextToken());
    }

    int ans = n;
    for (int i = 0; i <= n-2; i++) {
      for (int j = i+1; j < n; j++) {
        int avg = 0;
	int count = 0;
	for (int x = i; x <= j; x++) {
	  avg += flowers[x];
	  count++;
	}
	if (avg%count == 0) avg = avg/count;
        else continue;

        for (int x = i; x <= j; x++) {
	  if (flowers[x] == avg) {
	    ans++;
	    break;
          }
	}
      }
    }
    System.out.println(ans);
  }
}

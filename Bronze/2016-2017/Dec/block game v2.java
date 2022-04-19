import java.util.*;
import java.io.*;

class Main {
  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new FileReader("speeding.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("speeding.out")));

    int n = Integer.parseInt(in.readLine());

    String[][] boards = new String[n][2];

    for(int i = 0; i < n; i++) {
      StringTokenizer st = new StringTokenizer(in.readLine());
      for(int j = 0; j <2; j++) {
        boards[i][j] = st.nextToken();
      }
    }

    for(int i = 'a'; i < 'z'; i++) {
      int freqCnt = 0;
      for(int j = 0; j < n; j++) {
        int rowFreqs = 0;
        for(int k = 0; k < 2; k++) {
          String s = boards[j][k];
          int cnt = 0;
          for(int l = 0; l < s.length(); l++) {
            if(s.charAt(l) == i) {
              cnt++;
            }
          }
          if(rowFreqs < cnt) {
            rowFreqs = cnt;
          }
        }
        freqCnt += rowFreqs;
      }
      out.println(freqCnt);
    }

    in.close();
    out.close();

  }
}

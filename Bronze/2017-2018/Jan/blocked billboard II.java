import java.util.*;
import java.io.*;

class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new FileReader("billboard.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("billboard.out")));

    StringTokenizer st = new StringTokenizer(in.readLine());
    int ax1 = Integer.parseInt(st.nextToken());
    int ay1 = Integer.parseInt(st.nextToken());
    int ax2 = Integer.parseInt(st.nextToken());
    int ay2 = Integer.parseInt(st.nextToken());
    
    st = new StringTokenizer(in.readLine());
    int bx1 = Integer.parseInt(st.nextToken());
    int by1 = Integer.parseInt(st.nextToken());
    int bx2 = Integer.parseInt(st.nextToken());
    int by2 = Integer.parseInt(st.nextToken());

    int cornerCovered = 0;
    if(isCovered(bx1,by1,bx2,by2,ax1,ay1)) cornerCovered++;
    if(isCovered(bx1,by1,bx2,by2,ax2,ay1)) cornerCovered++;
    if(isCovered(bx1,by1,bx2,by2,ax1,ay2)) cornerCovered++;
    if(isCovered(bx1,by1,bx2,by2,ax2,ay2)) cornerCovered++;

    int area = (ax2-ax1)*(ay2-ay1);
    if(cornerCovered == 1 || cornerCovered == 0) out.println(area);
    if(cornerCovered == 2){
      out.println(area - overlap(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));
    }
    if(cornerCovered == 4) out.println(0);

    in.close();
    out.close();
  }

  static boolean isCovered(int x1, int y1, int x2, int y2, int p1, int p2) {
    if(p1 >= x1 && p1 <= x2 && p2 >= y1 && p2 <= y2) return true;
    else return false;
  }

  static int overlap (int x1, int y1, int x2, int y2, int px1, int py1, int px2, int py2)  {
    int xOverlap = Math.min(x2, px2) - Math.max(x1, px1);
    int yOverlap = Math.min(y2, py2) - Math.max(y1, py1);
    return xOverlap*yOverlap;
  }
}

  

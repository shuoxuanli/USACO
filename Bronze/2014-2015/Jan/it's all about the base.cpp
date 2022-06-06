#include<bits/stdc++.h>
using namespace std;

#define MAXB 15000

int evaluate(const string& num, int base) {
  return (num[0] - '0') * base * base + (num[1] - '0') * base + (num[2] - '0');
}

int main() {
  freopen("whatbase.in", "r", stdin);
  freopen("whatbase.out", "w", stdout);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    string x, y;
    cin >> x >> y;
    
    int vx = 10;
    int vy = 10;
    while (vx <= MAXB && vy <= MAXB) {
      int nx = evaluate(x, vx);
      int ny = evaluate(y, vy);
      if (nx < ny) {
        vx++;
      } else if (ny < nx) {
        vy++;
      } else {
        cout << vx << ' ' << vy << '\n';
        break;
      }
    }
  }
  return 0;
}

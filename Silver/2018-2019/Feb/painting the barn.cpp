#include <bits/stdc++.h>
using namespace std;

int barn[1010][1010];

int main() {
  freopen("paintbarn.in", "r", stdin);
  freopen("paintbarn.out", "w", stdout);

  int n, k;
  cin>>n>>k;

  int x1 = INT_MAX, y1 = INT_MAX, x2 = 0, y2 = 0;
  for(int i = 0; i < n; i++) {
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    x1 = min(x1, a);
    y1 = min(y1, b);
    x2 = max(x2, c);
    y2 = max(y2, d);
    for(int j = b; j < d; j++) {
      barn[j][a]++;
      barn[j][c]--;
    }
  }
  
  for(int i = y1; i <= y2; i++) {
    for(int j = x1; j <= x2; j++) {
      barn[i][j] += barn[i][j-1];
    }
  }

  int ans = 0;
  for(int i = y1; i <= y2; i++) {
    for(int j = x1; j <= x2; j++) {
      if(barn[i][j] == k) {
        ans++;
      }
    }
  }

  cout<<ans<<'\n';
  return 0;
}

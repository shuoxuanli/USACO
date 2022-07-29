#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct pt{
  ll x, y;
};

ll dis(ll x1, ll y1, ll x2, ll y2) {
  return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

ll h, g, dp[1001][1001][2];
pt a[1001], b[1001];

int main() {
  ifstream cin("checklist.in");
  ofstream cout("checklist.out");
  
  cin>>h>>g;

  for(int i = 0; i < h; i++) {
    cin>>a[i].x>>a[i].y;
  }

  for(int i = 0; i < g; i++) {
    cin>>b[i].x>>b[i].y;
  }

  for(int i = 0; i <= h; i++) {
    for(int j = 0; j <= g; j++) {
      dp[i][j][0] = 1e18;
      dp[i][j][1] = 1e18;
    }
  }
  
  dp[1][0][0] = 0;
  ll e;
  for(int i = 0; i <= h; i++) {
    for(int j = 0; j <= g; j++) {
      if(i > 0 && j > 0) {
        e = dis(a[i-1].x, a[i-1].y, b[j-1].x, b[j-1].y);
        dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1] + e);
        dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + e);
      }
      if(i > 1) {
        e = dis(a[i-1].x, a[i-1].y, a[i-2].x, a[i-2].y);
        dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0] + e);
      }
      if(j > 1) {
        e = dis(b[j-1].x, b[j-1].y, b[j-2].x, b[j-2].y);
        dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + e);
      }
    }
  }
  
  cout<<dp[h][g][0]<<endl;
  return 0;
} 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n, cows[2501][2501], dp[2501][2501];

struct pos{
  int x, y;
} cells[2501];

bool cmpx(pos a, pos b) {
  return a.x < b.x;
}

bool cmpy(pos a, pos b) {
  return a.y < b.y;
}

ll psum(int a, int b, int A, int B) {
  return (ll)dp[A+1][B+1] - dp[a][B+1] - dp[A+1][b] + dp[a][b];
}

int main() {
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>cells[i].x>>cells[i].y;
  }

  sort(cells, cells+n, cmpx);
  for(int i = 0; i < n; i++) cells[i].x = i+1;
  sort(cells, cells+n, cmpy);
  for(int i = 0; i < n; i++) cells[i].y = i+1;

  for(int i = 0; i < n; i++) cows[cells[i].x][cells[i].y] = 1;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + cows[i][j];
    }
  }
  
  ll ans = 1;
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      int l = min(cells[i].x, cells[j].x)-1;
      int r = max(cells[i].x, cells[j].x)-1;
      ans += psum(0,i,l,j)*psum(r,i,n-1,j);
    }
  }
  
  cout<<ans<<endl;
  return 0;
} 

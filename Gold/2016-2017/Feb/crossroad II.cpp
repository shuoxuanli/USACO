#include <bits/stdc++.h>
using namespace std;

int l[1001], r[1001], dp[1001][1001];
bool grid[1001][1001];

int main() {
  ifstream cin("nocxross.in");
  ofstream cout("nocross.out");
  
  int n;
  cin>>n;

  for(int i = 1; i <= n; i++) cin>>l[i];
  for(int i = 1; i <= n; i++) cin>>r[i];

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(abs(l[i] - r[j]) <= 4) {
        grid[i][j] = 1;
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
     dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1] + grid[i][j]));
    }
  }
  
  
  cout<<dp[n][n]<<endl;
  return 0;
} 

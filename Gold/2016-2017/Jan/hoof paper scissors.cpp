#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
int dp[maxN][25][3], game[maxN];

int main() {
  ifstream cin("hps.in");
  ofstream cout("hps.out");
  
  int n, k;
  cin>>n>>k;

  for(int i = 0; i < n; i++) {
    char c; cin>>c;
    if(c == 'H') game[i] = 0;
    if(c == 'P') game[i] = 1;
    if(c == 'S') game[i] = 2;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= k; j++) {
      for(int m = 0; m < 3; m++) {
        if(game[i] == m) dp[i][j][m]++;
        dp[i+1][j+1][0] = max(dp[i][j][m], dp[i+1][j+1][0]);
        dp[i+1][j+1][1] = max(dp[i][j][m], dp[i+1][j+1][1]);
        dp[i+1][j+1][2] = max(dp[i][j][m], dp[i+1][j+1][2]);
        dp[i+1][j][m] = max(dp[i+1][j][m], dp[i][j][m]);
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < 3; i++) {
    ans = max(ans, dp[n-1][k][i]);
  }

  cout<<ans<<endl;
  return 0;
} 

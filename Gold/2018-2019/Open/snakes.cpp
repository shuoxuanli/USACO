#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n, k, a[405], mxn[405][405], waste[405][405], dp[405][405];

int main() {
  ifstream cin("snakes.in");
  ofstream cout("snakes.out");

  cin>>n>>k;

  for(int i = 1; i <= n; i++) {
    cin>>a[i];
  }

  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j++) {
      for(int k = i; k <= j; k++) {
        mxn[i][j] = max(mxn[i][j], a[k]);
      }
    }
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j++) {
      for(int k = i; k <= j; k++) {
        waste[i][j] += mxn[i][j] - a[k];
      }
    }
  }

  memset(dp, 0x7f, sizeof(dp));
  for(int i = 1; i <= n; i++) {
    dp[i][0] = waste[1][i];
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= k; j++) {
      for(int m = i+1; m <= n; m++) {
        dp[m][j+1] = min(dp[m][j+1], dp[i][j] + waste[i+1][m]);
      }
    }
  }
  
  ll ans = LONG_MAX;
  for(int i = 0; i <= k; i++) {
    ans = min(ans, dp[n][i]);
  }

  cout<<ans<<endl;
  return 0;
} 

/*
 ID: shuoxua2
 PROG: maze1
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int t, n, k, a[55][55], dp[55][55][5][2];

int main() {
  cin>>t;
  while(t--) {
    cin>>n>>k;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        char c; cin>>c;
        a[i][j] = c == '.';
      }
    }
    memset(dp, 0, sizeof(dp));
    dp[1][1][0][0] = dp[1][1][0][1] = 1;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(!a[i][j]) continue;
        for(int l = 0; l <= k; l++) {
          dp[i][j][l][0] += dp[i-1][j][l][0];
          dp[i][j][l][1] += dp[i][j-1][l][1];
          if(l && (i-1 > 1 || j > 1)) 
            dp[i][j][l][0] += dp[i-1][j][l-1][1];
          if(l && (j-1 > 1 || i > 1)) 
            dp[i][j][l][1] += dp[i][j-1][l-1][0];
        }
      }
    }
    int ans = 0;
    for(int i = 1; i <= k; i++)
        ans += dp[n][n][i][0] + dp[n][n][i][1];
    cout<<ans<<endl;
  }
  return 0;
}

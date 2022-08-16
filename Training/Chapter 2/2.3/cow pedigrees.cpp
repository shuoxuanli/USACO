/*
 ID: shuoxua2
 PROG: nocows
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 9901;
int n, k, dp[205][105];

int main() {
  ifstream cin("nocows.in");
  ofstream cout("nocows.out");
  
  cin>>n>>k;

  for(int i = 0; i <= k; i++) {
    dp[1][i] = 1;
  }

  for(int j = 2; j <= k; j++) {
    for(int i = 2; i <= n; i++) {
      for(int k = 1; k < i; k++) {
        dp[i][j] = (dp[i][j] + dp[k][j-1]*dp[i-1-k][j-1])%MOD;
      }
    }
  }
  
  cout<<(dp[n][k]-dp[n][k-1]+MOD)%MOD<<endl;
  return 0;
} 

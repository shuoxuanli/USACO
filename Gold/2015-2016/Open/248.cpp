#include <bits/stdc++.h>
using namespace std;

int n, a[250], dp[250][250];

int main() {
  ifstream cin("248.in");
  ofstream cout("248.out");
  
  cin>>n;

  for(int i = 1; i <= n; i++) {
    cin>>a[i];
    dp[i][i] = a[i];
  }

  for(int i = n-1; i > 0; i--) {
    for(int j = i+1; j <= n; j++) {
      for(int k = i; k < j; k++) {
        if(dp[i][k] == dp[k+1][j]) {
          dp[i][j] = max(dp[i][j], dp[i][k]+1);
        }
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j++) {
      ans = max(ans, dp[i][j]);
    }
  }

  cout<<ans<<endl;
  return 0;
} 

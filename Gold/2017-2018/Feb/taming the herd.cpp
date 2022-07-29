#include <bits/stdc++.h>
using namespace std;

int n, a[105], dp[105][105][105];

int main() {
  ifstream cin("taming.in");
  ofstream cout("taming.out");
  
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>a[i];
  }

  memset(dp, 0x7f, sizeof(dp));
  
  dp[0][0][1] = a[0] != 0;
  for(int i = 1; i < n; i++) {
    for(int j = 0; j <= i; j++) {
      for(int k = 1; k <= i+1; k++) {
        if(j < i)
          dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]+(a[i]!=i-j));
        else 
          for(int l = 0; l < i; l++) 
            dp[i][j][k] = min(dp[i][j][k], dp[i-1][l][k-1] + (a[i]!=i-j));
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    int m = 0x7f7f7f7f;
    for(int j = 0; j < n; j++) {
      m = min(m, dp[n-1][j][i]);
    }
    cout<<m<<endl;
  }
  return 0;
} 

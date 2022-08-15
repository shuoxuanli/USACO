/*
 ID: shuoxua2
 PROG:subset
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int n, dp[50][2500];

int main() {
  ifstream cin("subset.in");
  ofstream cout("subset.out");
  
  cin>>n;

  int sum = n*(n+1)/2;

  if(sum&1) {
    cout<<0<<endl;
    return 0;
  }
  
  dp[0][0] = 1;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= sum; j++) {
      dp[i+1][j+i+1] += dp[i][j];
      dp[i+1][j] += dp[i][j];
    }
  }

  cout<<dp[n-1][sum/2]<<endl;;
  return 0;
} 

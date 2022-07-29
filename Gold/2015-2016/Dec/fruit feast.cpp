#include <bits/stdc++.h>
using namespace std;

int t, a, b, dp[5000005][2];

int main() {
  ifstream cin("feast.in");
  ofstream cout("feast.out");
  
  cin>>t>>a>>b;

  dp[0][0] = 1;
  dp[0][1] = 1;
  for(int i = 0; i <= t; i++) {
    if(i >= a && dp[i-a][0]) {
      dp[i][0] = 1;
      dp[i/2][1] = 1;
    }
    if(i >= b && dp[i-b][0]) {
      dp[i][0] = 1;
      dp[i/2][1] = 1;
    }
  }

  for(int i = 0; i <= t; i++) {
    if(i >= a && dp[i-a][1]) {
      dp[i][1] = 1;
    }
    if(i >= b && dp[i-b][1]) {
      dp[i][1] = 1;
    }
  }

  for(int i = t; i >= 0; i--) {
    if(dp[i][0] || dp[i][1]) {
      cout<<i<<endl;;
      return 0;
    }
  }
} 

#include <bits/stdc++.h>
using namespace std;

int n, k, s[10005], team[10005][1005], dp[10005];

int main() {
  ifstream cin("teamwork.in");
  ofstream cout("teamwork.out");
  
  cin>>n>>k;

  for(int i = 1; i <= n; i++) {
    cin>>s[i];
  }

  for(int i = 1; i <= n; i++) {
    int pre = 0;
    for(int j = 0; j < k; j++) {
      pre = max(pre, s[i+j]);
      team[i][j] = pre*(j+1);
    }
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < k; j++) {
      dp[i+j] = max(dp[i+j], dp[i-1] + team[i][j]);
    }
  }

  cout<<dp[n]<<endl;
  return 0;
} 

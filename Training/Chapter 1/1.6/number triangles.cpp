/*
 ID: Shuoxuan Li [shuoxua2]
 LANG: C++
 TASK: numtri
*/
#include <bits/stdc++.h>
using namespace std;

int a[1001][1001], dp[1001][1001];

int main() {
  ifstream cin("numtri.in");
  ofstream cout("numtri.out");
  
  int r;
  cin>>r;

  for(int i = 1; i <= r; i++) {
    for(int j = 1; j <= i; j++) {
      cin>>a[i][j];
    }
  }

  for(int i = r; i > 0; i--) {
    for(int j = 1; j <= i; j++) {
      dp[i][j] = max(dp[i][j], dp[i+1][j] + a[i][j]);
      dp[i][j] = max(dp[i][j], dp[i+1][j+1] + a[i][j]);
    }
  }

  cout<<dp[1][1]<<endl;
  return 0;
} 

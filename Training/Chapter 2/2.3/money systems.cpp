/*
 ID: shuoxua2
 PROG: money
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int v, n, a[25];
ll dp[10005];

int main() {
  ifstream cin("money.in");
  ofstream cout("money.out");
  cin>>v>>n;
  for(int i = 0; i < v; i++)
    cin>>a[i];
  dp[0] = 1;
  for(int i = 0; i < v; i++) {
    for(int j = 0; j+a[i] <= n; j++) {
      dp[j+a[i]] += dp[j];
    }
  }
  
  cout<<dp[n]<<endl;
}

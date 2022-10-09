#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, MOD, lpf[10001];
ll dp[10001];

int main() {
  ifstream cin("exercise.in");
  ofstream cout("exercise.out");
  
  cin>>n>>MOD;
  
  vector<int> p;
  for(int i = 2; i <= n; i++) {
    if(!lpf[i]) {
      p.push_back(i);
      for(int j = i; j <= n; j += i) {
        lpf[j] = i;
      }
    }
  }
  
  
  for(int i = 0; i <= n; i++) {
    dp[i] = 1;
  }
  
  for(int i = 1; i <= sz(p); i++) {
    for(int j = n; j >= 0; j--) {
      int k = p[i-1];
      while(k <= j) {
        dp[j] = (dp[j] + k * dp[j-k]%MOD)%MOD;
        k *= p[i-1];
      }
    }
  }
  
  cout<<dp[n]<<'\n';
  return 0;
}

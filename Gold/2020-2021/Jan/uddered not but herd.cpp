#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int stor1[1<<10][20], stor2[1<<10][20], adj[21][21], dp[1<<21];
 
int main() {
  string s; cin >> s;
  map<char,int> m; for(char c: s) m[c] = 0;
  int cnt = 0; for (auto& t: m) t.s = cnt++;
  int n = m.size();
  for (int i = 0; i+1 < s.size(); ++i) 
    ++adj[m[s[i]]][m[s[i+1]]];
  fill(dp, dp+(1<<n), 1e9);
  dp[0] = 1;
  int bits = n/2;
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < 1<<bits; ++i) 
      for (int k = 0; k < bits; ++k) 
        if (i&(1<<k)) stor1[i][j] += adj[k][j];
    for (int i = 0; i < 1<<(n-bits); ++i) 
      for (int k = 0; k < n-bits; ++k) 
        if (i&(1<<k)) stor2[i][j] += adj[bits+k][j];
  }
  for (int i = 0; i < 1<<n; ++i)
    for (int j = 0; j < n; ++j) 
      if (i&(1<<j)) {
        int sum = dp[i^(1<<j)];
        sum += stor1[i&((1<<bits)-1)][j];
        sum += stor2[i>>bits][j];
        dp[i] = min(dp[i],sum);
      }
  cout << dp[(1<<n)-1] << "\n";
  return 0;
}

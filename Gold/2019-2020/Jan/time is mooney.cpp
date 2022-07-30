#include <bits/stdc++.h>
using namespace std;

int n, m, c, a, moonies[1005], dp[1005][1005];
vector<int> adj[1005];

int main() {
  ifstream cin("time.in");
  ofstream cout("time.out");
  
  cin>>n>>m>>c;

  for(int i = 1; i <= n; i++) {
    cin>>moonies[i];
  }
  
  for(int i = 0; i < m; i++) {
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
  }

  memset(dp, -1, sizeof(dp));
  
  dp[0][1] = 0;
  int ans = 0;
  for(int t = 0; t < 1000; t++) {
    for(int i = 1; i <= n; i++) {
      if(dp[t][i] != -1) {
        for(int u : adj[i]) {
          dp[t+1][u] = max(dp[t+1][u], dp[t][i] + moonies[u]);
        }
      }
    }
    ans = max(dp[t][1] - c*t*t, ans);
  }
  
  cout<<ans<<endl;
} 

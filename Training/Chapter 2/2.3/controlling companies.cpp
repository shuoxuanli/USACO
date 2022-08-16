/*
 ID: shuoxua2
 PROG: concom
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, m = 100, dp[101][101];
bool vis[101][101];

void dfs(int u, int v) {
  if(vis[u][v]) return;
  vis[u][v] = 1;
  for(int i = 1; i <= m; i++)
    dp[u][i] += dp[v][i];
  for(int i = 1; i <= m; i++) {
    if(vis[i][u])
      dfs(i, v);
  }
  for(int i = 1; i <= m; i++) {
    if(dp[u][i] > 50) 
      dfs(u, i);
  }
}

void add(int a, int b, int p) {
  for(int i = 1; i <= m; i++)
    if(vis[i][a]) 
      dp[i][b] += p;
  for(int i = 1; i <= m; i++)
    if(dp[i][b] > 50)
      dfs(i, b);
}

int main() {
  ifstream cin("concom.in");
  ofstream cout("concom.out");
  cin>>n;
  for(int i = 1; i <= m; i++)
    vis[i][i] = 1;
  for(int i = 0; i < n; i++) {
    int a, b, p;
    cin>>a>>b>>p;
    add(a, b, p);
  }
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= m; j++) {
      if(i^j && vis[i][j]) {
        cout<<i<<' '<<j<<endl;
      }
    }
  }
}

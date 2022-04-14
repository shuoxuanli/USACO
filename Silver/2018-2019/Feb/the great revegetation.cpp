#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
int n, m, vis[maxN];
bool imp;
vector<int> d[maxN], s[maxN];

void dfs(int u, int v) {
  vis[u] = v;

  for(int j : s[u]) {
    if(vis[j] == 3-v) imp = true;
    if(vis[j] == 0) dfs(j, v);
  }

  for(int j : d[u]) {
    if(vis[j] == v) imp = true;
    if(vis[j] == 0) dfs(j, 3-v);
  }
}

int main() {
  ifstream cin("revegetate.in");
  ofstream cout("revegetate.out");

  cin>>n>>m;

  for(int i = 1; i <= m; i++) {
    char c; int a, b;
    cin>>c>>a>>b;
    if(c == 'S') {
      s[a].push_back(b); s[b].push_back(a);
    } else {
      d[a].push_back(b); d[b].push_back(a);
    }
  }

  int ans = 0; 
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      dfs(i, 1);
      ans++;
    }
  }

  if(imp) {
    cout<<0<<endl;
    return 0;
  }

  cout<<1;
  for(int i = 0; i < ans; i++) {
    cout<<0;
  }
  cout<<endl;
  return 0;
} 

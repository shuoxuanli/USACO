#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
int n,k, pos[maxN], f[maxN];
vector<int> adj[maxN];
set<int> ans[maxN];

int find(int u) {
  if(f[u] == u) {
    return u;
  }
  f[u] = find(f[u]);
  return f[u];
}

void dsu(int u, int v) {
  int fu = find(u);
  int fv = find(v);
  if(fu != fv) {
    f[fu] = fv;
  }
  return;
}

int main() {
  cin>>n>>k;

  for(int i = 1; i <= n; i++) {
    f[i] = i;
    pos[i] = i;
    adj[i].push_back(i);
  }
  
  for(int i = 0; i < k; i++) {
    int a, b;
    cin>>a>>b;
    adj[pos[a]].push_back(b);
    adj[pos[b]].push_back(a);
    swap(pos[a], pos[b]);
  }

  for(int i = 1; i <= n; i++) {
    dsu(i, pos[i]);
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < adj[pos[i]].size(); j++) {
      ans[find(pos[i])].insert(adj[pos[i]][j]);
    }
  }

  for(int i = 1; i <= n; i++) {
    cout<<ans[find(i)].size()<<endl;
  }

  return 0;
} 

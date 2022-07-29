#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+1;
int n, m, perm[maxN], f[maxN], team;
vector<int> adj[maxN];
bool open[maxN];
string ans[maxN];

int find(int u) {
  if(f[u] == u) {
    return u;
  }
  return f[u] = find(f[u]);
}

void dsu(int u, int v) {
  int fu = find(u);
  int fv = find(v);
  if(fu != fv) {
    team--;
    f[fu] = fv;
  }
  return;
}

int main() {
  ifstream cin("closing.in");
  ofstream cout("closing.out");

  cin>>n>>m;

  for(int i = 0; i < m; i++) {
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <= n; i++) {
    cin>>perm[i];
    f[i] = i;
  }

  ans[n] = "YES";
  open[perm[n]] = 1;
  team = 1;
  for(int i = n-1; i >= 1; i--) {
    team++;
    open[perm[i]] = 1;
    for(int node: adj[perm[i]]) {
      if(open[node]) {
        dsu(node, perm[i]);
      }
    }
    ans[i] = (team==1) ? "YES":"NO";
  }

  for(int i = 1; i <= n; i++) {
    cout<<ans[i]<<endl;
  }
  return 0;
} 

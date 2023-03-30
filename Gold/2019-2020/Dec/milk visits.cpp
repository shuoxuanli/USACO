#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 1E5 + 1;
int n, q, a[N], ans[N];
int t = 0, tin[N], tout[N];
vector<int> trav, adj[N];
vector<array<int, 3>> qry[N];
vector<pair<int, int>> col[N];

void dfs1(int u, int p) {
  tin[u] = ++t;
  for (int v : adj[u]) if (v != p) {
    dfs1(v, u);
  }
  tout[u] = t;
}

bool anc(int u, int v) { 
  return tin[u] <= tin[v] && tout[u] >= tout[v]; 
}

void dfs2(int u, int p, int d) {
  trav.push_back(u);
  col[a[u]].push_back({u, d});
  for (auto [v, c, i] : qry[u]) {
    if (col[c].empty()) continue;
    if (!anc(col[c].back().first, v))
      ans[i] = 1;
    if (!anc(trav[col[c].back().second + 1], v))
      ans[i] = 1;
  }
  for (int v : adj[u]) if (v != p) {
    dfs2(v, u, d + 1);
  }
  trav.pop_back();
  col[a[u]].pop_back();
}

int main() {
  ifstream cin("milkvisits.in");
  ofstream cout("milkvisits.out");

  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    qry[a].push_back({b, c, i});
    qry[b].push_back({a, c, i});
  }

  dfs1(1, 0);
  dfs2(1, 0, 0);

  for (int i = 0; i < q; i++)
    cout << ans[i];
  return 0;
}

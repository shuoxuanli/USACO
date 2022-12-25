#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, q;
char c[200001];
vector<int> adj[100001];
bool nv[100001], ev[200001], vis[100001];
int x[200001], y[200001], ans[100001];

int main() {
  cin >> n >> q;

  vector<pair<int, int>> e;
  for (int i = 1; i <= q; i++) {
    cin >> c[i];
    if (c[i] == 'D') {
      cin >> x[i];
      nv[x[i]] = true;
    } else if (c[i] == 'R') {
      int j;
      cin >> j, --j;
      ev[j] = true;
      x[i] = e[j].first;
      y[i] = e[j].second;
    } else {
      cin >> x[i] >> y[i];
      e.push_back({x[i], y[i]});
    }
  }

  function<void(int, int)> dfs = [&](int u, int t) {
    if (vis[u])
      return;
    ans[u] = t;
    vis[u] = true;
    for (int v : adj[u]) {
      dfs(v, t);
    }
  };

  auto upd = [&](int u, int v, int t) {
    if (ans[u] || ans[v]) {
      dfs(v, t);
      dfs(u, t);
    } else {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  };

  for (int i = 1; i <= n; i++) {
    if (!nv[i]) {
      dfs(i, q);
    }
  }
  for (int i = 0; i < sz(e); i++) {
    if (!ev[i]) {
      upd(e[i].first, e[i].second, q);
    }
  }

  for (int i = q; i > 0; i--) {
    if (c[i] == 'D') {
      dfs(x[i], i - 1);
    } else if (c[i] == 'R') {
      upd(x[i], y[i], i - 1);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}

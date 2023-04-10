#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 1E5 + 1;
int n, k = 0, t[N], siz[N];
ll w[N], f[N], g[N];
vector<int> adj[N];

void dfs1(int u = 1, int p = 0) {
  k += t[u];
  siz[u] = t[u];
  for (int v : adj[u]) if (v != p) {
    dfs1(v, u);
    siz[u] += siz[v];
    if (t[v]) {
      g[u] += w[v];
    } else {
      f[u] += f[v] + siz[v];
      g[u] += g[v] + w[v] * siz[v];
    }
  }
}

void dfs2(int u = 1, int p = 0) {
  for (int v : adj[u]) if (v != p && !t[v]) {
    f[v] = f[u] + k - 2 * siz[v];
    g[v] = g[u] - siz[v] * w[v] + (k - siz[v]) * 2;
    dfs2(v, u);
  }
}

int main() {
  ifstream cin("dirtraverse.in");
  ofstream cout("dirtraverse.out");

  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    int m, v;
    cin >> s >> m;
    w[i] = sz(s);
    t[i] = m == 0;
    for (int j = 0; j < m; j++) {
      cin >> v;
      adj[i].push_back(v);
    }
  }

  dfs1();
  dfs2();

  ll ans = LLONG_MAX;
  for (int i = 1; i <= n; i++) if (!t[i]) {
    ans = min(ans, f[i] + g[i]);
  }
  cout << ans << '\n';
  return 0;
}

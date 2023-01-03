#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

template <class T> struct bit {
  const int n;
  vector<T> c;
  bit(int n) : n(n), c(n + 1) {}
  void upd(int i, T v) {
    for (; i <= n; i += i & -i) c[i] ^= v;
  }
  T qry(int i) {
    T res = 0;
    for (; i > 0; i -= i & -i) res ^= c[i];
    return res;
  }
  T qry(int l, int r) { return qry(r) ^ qry(l - 1); }
};

int n, q, t = 0, in[100001], out[100001];
ll a[100001], up[100001][21];
vector<int> adj[100001];

void dfs(int u, int p) {
  in[u] = ++t;
  up[u][0] = p;
  for (int i = 1; i <= 20; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (int v : adj[u]) if (v != p) {
    dfs(v, u);
  }
  out[u] = t;
}

bool anc(int u, int v) { 
  return in[u] <= in[v] && out[u] >= out[v]; 
}

int lca(int u, int v) {
  if (anc(u, v)) return u;
  for (int i = 20; i >= 0; i--) {
    if (up[u][i] > 0 && !anc(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}

int main() {
  ifstream cin("cowland.in");
  ofstream cout("cowland.out");

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);

  bit<int> f(n);
  for (int i = 1; i <= n; i++) {
    f.upd(in[i], a[i]);
    f.upd(out[i] + 1, a[i]);
  }

  while (q--) {
    int opt, i, j;
    cin >> opt >> i >> j;
    if (opt == 1) {
      f.upd(in[i], a[i] ^ j);
      f.upd(out[i] + 1, a[i] ^ j);
      a[i] = j;
    } else {
      int p = lca(i, j);
      cout << (f.qry(in[p], in[i]) ^ f.qry(in[p], in[j]) ^ a[p]) << '\n';
    }
  }
  return 0;
}

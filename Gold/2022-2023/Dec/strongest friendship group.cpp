#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

template <class T> struct dsu {
  vector<int> f;
  vector<T> rank;
  dsu(int n) : f(n + 1), rank(n + 1, 1) { 
    iota(f.begin(), f.end(), 0); 
  }
  int find(int x) { 
    return f[x] == x ? x : f[x] = find(f[x]); 
  }
  bool join(int x, int y) {
    if ((x = find(x)) == (y = find(y)))
      return false;
    if (rank[x] < rank[y]) swap(x, y);
    rank[x] += rank[y], f[y] = x;
    return true;
  }
  T size(int x) { return rank[find(x)]; }
  bool same(int x, int y) { return find(x) == find(y); }
};

int n, m, deg[200005];
bool vis[200005], rem[200005], e[200005];
vector<int> adj[200005];

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++, deg[v]++;
  }

  using pll = pair<ll, ll>;
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  for (int i = 1; i <= n; i++) pq.push({deg[i], i});

  vector<pll> ord;
  while (!pq.empty()) {
    ll w, u;
    tie(w, u) = pq.top();
    pq.pop();
    if (rem[u]) continue;
    rem[u] = true;
    for (int v : adj[u]) {
      pq.push({--deg[v], v});
    }
    ord.push_back({u, w});
  }
  reverse(ord.begin(), ord.end());

  ll ans = 0;
  dsu<int> d(n);
  for (auto [u, w] : ord) {
    e[u] = true;
    for (int v : adj[u]) if (e[v]) {
      d.join(u, v);
    }
    ans = max(ans, w * d.size(u));
  }

  cout << ans << '\n';
  return 0;
}

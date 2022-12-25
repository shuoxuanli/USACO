#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

template <class T> struct dsu {
  vector<int> f;
  vector<T> rank;
  dsu(int n) : f(n+1), rank(n+1, 1) { 
    iota(f.begin(), f.end(), 0); 
  }
  int find(int x) { 
    return f[x] == x ? x : f[x] = find(f[x]); 
  }
  bool join(int x, int y) {
    if ((x = find(x)) == (y = find(y)))
      return false;
    if (rank[x] < rank[y])
      swap(x, y);
    rank[x] += rank[y], f[y] = x;
    return true;
  }
  T size(int x) { return rank[find(x)]; }
  bool same(int x, int y) { return find(x) == find(y); }
};

int n, m, siz[200005];
bool vis[200005], rem[200005], e[200005];
vector<int> adj[200005];

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    siz[u]++, siz[v]++;
  }

  int g = 0;
  using pll = pair<ll, ll>;
  priority_queue<pll, vector<pll>, greater<pll>> pq;

  function<void(int)> dfs = [&](int u) {
    g++;
    vis[u] = true;
    pq.push({siz[u], u});
    for (int v : adj[u]) if (!vis[v]) {
      dfs(v);
    }
  };

  auto get = [&]() {
    vector<pll> v;
    while (!pq.empty() && g) {
      ll w, u;
      tie(w, u) = pq.top();
      pq.pop();
      if (rem[u]) continue;
      rem[u] = true;
      for (int v : adj[u]) {
        pq.push({--siz[v], v});
      }
      v.push_back({u, w});
      g--;
    }
    while (sz(pq)) pq.pop();
    reverse(v.begin(), v.end());
    return v;
  };

  ll ans = 0;
  dsu<int> d(n);
  for (int i = 1; i <= n; i++) if (!vis[i]) {
    g = 0;
    dfs(i);
    auto ord = get();
    for (auto [u, w] : ord) {
      e[u] = true;
      for (int v : adj[u]) if (e[v]) {
        d.join(u, v);
      }
      ans = max(ans, w * d.size(u));
    }
  }

  cout << ans << '\n';
  return 0;
}

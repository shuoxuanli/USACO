#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n;
ll m, ans = 0, a[200005], deg[200005];
vector<int> adj[200005];
vector<pair<int, ll>> op[200005];

void dfs(int u = 1, int p = -1) {
  for (int v : adj[u]) if (v != p) {
    dfs(v, u);
    ans += a[v] != m;
    a[u] += a[v] - m;
    if (a[v] > m) {
      deg[u]++;
      op[v].push_back({u, a[v] - m});
    } else if (a[v] < m) {
      deg[v]++;
      op[u].push_back({v, m - a[v]});
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  m = accumulate(a + 1, a + 1 + n, 0LL) / n;

  dfs();

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!deg[i]) q.push(i);
  }

  cout << ans << '\n';
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto [v, w] : op[u]) {
      cout << u << ' ' << v << ' ' << w << '\n';
      if (!(--deg[v])) q.push(v);
    }
  }
  return 0;
}

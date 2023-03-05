#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

struct edge {
  int id, to, t1, t2;
};

int n, m;
vector<edge> adj[200001];
int a[200001], ans[200001], cnt = 0;

void dfs(int u, int t) {
  ans[u] = t;
  cnt += u == 1;
  while (!adj[u].empty()) {
    int w = (u == 1 && cnt == 1) ? 0 : a[u];
    if (adj[u].back().t1 < t + w) break;
    if (ans[adj[u].back().to] > adj[u].back().t2) {
      dfs(adj[u].back().to, adj[u].back().t2);
    }
    adj[u].pop_back();
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, t1, t2;
    cin >> a >> t1 >> b >> t2;
    adj[a].push_back({i, b, t1, t2});
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sort(adj[i].begin(), adj[i].end(), [](const edge &a, const edge &b) {
      return a.t1 < b.t1; 
    });
  }

  memset(ans, 0x3f, sizeof(ans));
  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << (ans[i] == 0x3f3f3f3f ? -1 : ans[i]) << '\n';
  }
  return 0;
}

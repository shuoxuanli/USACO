#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

struct edge {
  int id, to, t1, t2;
  bool operator<(const edge &o) const { 
    return t1 < o.t1; 
  }
};

int n, m;
priority_queue<edge> adj[200001];
int a[200001], ans[200001], cnt = 0;

void dfs(int u, int t) {
  ans[u] = t;
  cnt += u == 1;
  int w = (u == 1 && cnt == 1) ? 0 : a[u];
  while (!adj[u].empty() && adj[u].top().t1 >= t + w) {
    auto v = adj[u].top();
    adj[u].pop();
    if (ans[v.to] > v.t2) dfs(v.to, v.t2);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, t1, t2;
    cin >> a >> t1 >> b >> t2;
    adj[a].push({i, b, t1, t2});
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  memset(ans, 0x3f, sizeof(ans));
  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << (ans[i] == 0x3f3f3f3f ? -1 : ans[i]) << '\n';
  }
  return 0;
}

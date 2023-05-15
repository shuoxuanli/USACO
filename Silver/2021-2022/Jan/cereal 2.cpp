#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 1E5 + 1;
int n, m;
vector<array<int, 3>> adj[N];
bool v1[N], v2[N], c1[N], c2[N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i, 0});
    adj[v].push_back({u, i, 1});
  }

  vector<int> p;
  for (int i = 1; i <= m; i++) if (!v1[i]) {
    int x = i, y = -1;
    auto bfs = [&](int st, bool *vis, bool *cnt, bool psh) {
      queue<int> q;
      q.push(st);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (auto [v, c, o] : adj[u]) {
          if (!vis[v] && !cnt[c]) {
            vis[v] = true;
            cnt[c] = true;
            q.push(v);
            if (psh) p.push_back(c);
          } else if (!psh && !cnt[c]) {
            x = o ? v : u;
            y = c;
          }
        }
      }
    };

    bfs(x, v1, c1, false);
    if (y != -1) {
      c2[y] = true;
      p.push_back(y);
    }
    bfs(x, v2, c2, true);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!c2[i]) {
      ans++;
      p.push_back(i);
    }
  }

  cout << ans << '\n';
  for (int i = 0; i < n; i++)
    cout << p[i] << '\n';
  return 0;
}

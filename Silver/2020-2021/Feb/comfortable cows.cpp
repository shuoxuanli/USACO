#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, g[3000][3000], ans = 0;

void bfs(int i, int j) {
  queue<pair<int, int>> q;
  q.push({i, j});
  while(!q.empty()) {
    int r, c;
    tie(r, c) = q.front(), q.pop();
    if(g[r][c]) continue;
    g[r][c] = 1, ans++;
    auto upd = [&](int r, int c) {
      if(!g[r][c]) return;
      int adj = 0;
      for(int k = 0; k < 4; k++) {
        int nr = r + d[k][0], nc = c + d[k][1];
        adj += g[nr][nc];
      }
      if(adj == 3) for(int k = 0; k < 4; k++) {
        int nr = r + d[k][0], nc = c + d[k][1];
        if(!g[nr][nc]) q.push({nr, nc});
      }
    };
    upd(r, c);
    for(int k = 0; k < 4; k++) {
      int nr = r + d[k][0], nc = c + d[k][1];
      upd(nr, nc);
    }
  }
}

int main() {
  cin>>n;
  for(int i = 0; i < n; i++) {
    int x, y; cin>>x>>y;
    x += 1000, y += 1000;
    bfs(x, y);
    cout<<ans-i-1<<'\n';
  }
  return 0;
}

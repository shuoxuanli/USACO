#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

const int maxN = 255*255;
map<int, int> h;
int n, mat[255][255], a[maxN], b[maxN];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
unordered_set<int> adj[maxN];
bool vis[255][255], tot[255][255];

void bfs(int r, int c, int u, int v) {
  queue<pi> q;
  q.push({r,c});
  int cnt = 0;
  bool x = 0;
  while(!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    if(vis[r][c]) continue;
    
    cnt++;
    vis[r][c] = 1;
    for(int i = 0; i < 4; i++) {
      int nr = r + dx[i];
      int nc = c + dy[i];
      if(nr < 1 || nr > n || nc < 1 || nc > n) 
        continue;
      if(mat[nr][nc] == v) x = 1;
      if(u != v && mat[nr][nc] == u) tot[nr][nc] = 1;
      if(mat[nr][nc] == u || mat[nr][nc] == v)
        q.push({nr, nc});
      else if(u == v) 
        adj[u].insert(mat[nr][nc]);
    }
  }
  if(u==v) a[u] = max(a[u], cnt);
  else if (x) b[u] = max(b[u], cnt);
}

int main() {
  ifstream cin("multimoo.in");
  ofstream cout("multimoo.out");
  
  cin>>n;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin>>mat[i][j];
      if(!h.count(mat[i][j])) {
        h[mat[i][j]] = h.size();
      }
      mat[i][j] = h[mat[i][j]];
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(!vis[i][j]) {
        bfs(i, j, mat[i][j], mat[i][j]);
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(!tot[i][j]) {
        for(int node : adj[mat[i][j]]) {
          if(node != mat[i][j]) {
            memset(vis, 0, sizeof(vis));
            bfs(i, j, mat[i][j], node);
          }
        }
      }
    }
  }

  int d = 0, t = 0;
  for(int i = 0; i <= h.size(); i++) {
    d = max(d, a[i]);
  }
  for(int i = 0; i <= h.size(); i++) {
    t = max(t, b[i]);
  }
  
  cout<<d<<endl;
  cout<<t<<endl;
  return 0;
} 

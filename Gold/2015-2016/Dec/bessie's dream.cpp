#include <bits/stdc++.h>
using namespace std;

struct st {
  int x, y, p;
  bool s;
};

int n, m, mat[1005][1005], ans = INT_MAX;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
bool vis[1005][1005][2];

struct cmp {
  bool operator() (st a, st b) {
    return a.p > b.p;
  }
};

void bfs() {
  priority_queue<st, vector<st>, cmp> q;
  q.push({1,1,0,0});
  while(!q.empty()) {
    int r = q.top().x;
    int c = q.top().y;
    int p = q.top().p;
    bool s = q.top().s;
    q.pop();

    if(r == n && c == m) {
      ans = min(ans, p);
      break;
    }
    if(vis[r][c][s]) continue;
    
    vis[r][c][s] = 1;
    for(int i = 0; i < 4; i++) {
      int nr = r + dx[i];
      int nc = c + dy[i];
      if(nr < 1 || nr > n || nc < 1 || nc > m || !mat[nr][nc]) 
        continue;
      if (mat[nr][nc] == 1) {
        q.push({nr, nc, p+1, s});
      }
      else if(mat[nr][nc] == 2) {
        q.push({nr, nc, p+1, 1});
      }
      else if(mat[nr][nc] == 3 && s) {
        q.push({nr, nc, p+1, 1});
      } 
      else if(mat[nr][nc] == 4) {
        while(nr <= n && nr > 0 && nc > 0 && nc <= m && 
          mat[nr][nc] == 4) {
          nr += dx[i], nc += dy[i];
        }
        if(nr > n || nr < 1 || nc < 1 || nc > m) 
          nr -= dx[i], nc -= dy[i];
        else if(!mat[nr][nc] || mat[nr][nc] == 3)
          nr -= dx[i], nc -= dy[i];
        bool ns = (mat[nr][nc] == 2);
        int diff = abs(nr-r) + abs(nc-c);
        q.push({nr, nc, p+diff, ns});
      }
    }
  }
}

int main() {
  ifstream cin("dream.in");
  ofstream cout("dream.out");
  
  cin>>n>>m;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin>>mat[i][j];
    }
  }

  bfs();
  cout<<((ans==INT_MAX)?-1:ans)<<endl;
} 

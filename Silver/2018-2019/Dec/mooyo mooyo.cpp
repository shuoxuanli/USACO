#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
int n, k, grid[101][11], dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1}, cnt = 0;
bool vis[101][11];

void bfs(int x, int y) {
  queue<pi> q;
  q.push(make_pair(x,y));
  while(!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    if(vis[r][c]) {
      continue;
    }
    
    cnt++;
    vis[r][c] = 1;

    for(int i = 0; i < 4; i++) {
      if(r+dx[i] >= 1 && r+dx[i] <= n && c+dy[i] >= 1 && c+dy[i] <= 10 
      && !vis[r+dx[i]][c+dy[i]] 
      && grid[r+dx[i]][c+dy[i]] == grid[x][y]) {
        q.push(make_pair(r+dx[i], c+dy[i]));
      }
    }
  }
}

void fill() {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= 10; j++) {
      if(vis[i][j]) {
        grid[i][j] = 0;
      }
    }
  }
}

void gravity() {
  queue<int> q[10];
  for(int j = 1; j <= 10; j++) {
    for(int i = n; i >= 1; i--) {
      if(grid[i][j] != 0) {
        q[j-1].push(grid[i][j]);
      }
    }
  }

  for(int j = 1; j <= 10; j++) {
    for(int i = n; i >= 1; i--) {
      if(!q[j-1].empty()) {
        grid[i][j] = q[j-1].front();
        q[j-1].pop();
      } else {
        grid[i][j] = 0;
      }
    }
  }
}

int main() {
  ifstream cin("mooyomooyo.in");
  ofstream cout("mooyomooyo.out");
  
  cin>>n>>k;

  for(int i = 1; i <= n; i++) {
    string s; cin>>s;
    for(int j = 1; j <= 10; j++) {
      grid[i][j] = s[j-1] - 48;
    }
  }

  bool found = true;
  while(found) {
    found = false;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= 10; j++) {
        if(grid[i][j] != 0) {
          cnt = 0;
          bfs(i,j);
          if(cnt >= k) {
            found = true;
            fill();
          }
          memset(vis, false, sizeof(vis));
        }
      }
    }
    gravity();
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= 10; j++) {
      cout<<grid[i][j];
    }
    cout<<endl;
  }
  return 0;
} 

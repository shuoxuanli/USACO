#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

int n, k, r, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
bool vis[101][101], cow[101][101];
vector<pi> road[101][101];

void bfs(int x, int y) {
  queue<pi> q;
  q.push(make_pair(x, y));
  while(!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    
    if(r < 1 || r > n || c < 1 || c > n || vis[r][c]) {
      continue;
    }
    
    vis[r][c] = 1;

    for(int i = 0; i < 4; i++) {
      bool rd = false;
      for(pi j : road[r][c]) {
        if(r+dx[i] == j.first && c+dy[i] == j.second) {
          rd = true;
        }
      }
      if(!rd) {
        q.push(make_pair(r+dx[i], c + dy[i]));
      }
    }
  }
}

int distant() {
  int ret = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(!vis[i][j] && cow[i][j]) {
        ret++;
      }
    }
  }
  return ret;
}

int main() {
  ifstream cin("countcross.in");
  ofstream cout("countcross.out");
  
  cin>>n>>k>>r;

  for(int i = 0; i < r; i++) {
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    road[x1][y1].push_back(make_pair(x2, y2));
    road[x2][y2].push_back(make_pair(x1, y1));
  }

  for(int i = 0; i < k; i++) {
    int a, b;
    cin>>a>>b;
    cow[a][b] = 1;
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(cow[i][j]) {
        bfs(i,j);
        ans += distant();
        memset(vis, false, sizeof(vis));
      }
    }
  }

  cout<<ans/2<<endl;
  return 0;
} 

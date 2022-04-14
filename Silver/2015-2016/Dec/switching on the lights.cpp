#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

struct pt{
  int x, y;
};

vector<pt> lights[101][101];
bool lit[101][101], vis[101][101], re[101][101];
int n, m, ans = 0, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

void bfs(int x, int y) {
  queue<pi> pq;
  pq.push(make_pair(x,y));
  while(!pq.empty()) {
    queue<pi> tmp = pq;
    bool end = true;
    while(!tmp.empty()) {
      if(!re[tmp.front().first][tmp.front().second]) {
        end = false;
      }
      tmp.pop();
    }
    if(end) {
      break;
    }
    int r = pq.front().first;
    int c = pq.front().second;
    pq.pop();

    if(r < 1 || r > n || c < 1 || c > n || vis[r][c]) {
      continue;
    }
    else if(!lit[r][c]) {
      re[r][c] = 1;
      pq.push({r,c});
      continue;
    }

    for(pt p : lights[r][c]) {
      lit[p.x][p.y] = 1;
    }

    vis[r][c] = 1;
    for(int i = 0; i < 4; i++) {
      pq.push(make_pair(r+dx[i], c + dy[i]));
    }
  }
}

int main() {
  ifstream cin("lightson.in");
  ofstream cout("lightson.out");
  
  cin>>n>>m;

  for(int i = 0; i < m; i++) {
    int x, y, a, b;
    cin>>x>>y>>a>>b;
    lights[x][y].push_back({a,b});
  }

  lit[1][1] = 1;
  bfs(1,1);

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(lit[i][j]) {
        ans++;
      }
    }
  }
  
  cout<<ans<<endl;
  return 0;
}

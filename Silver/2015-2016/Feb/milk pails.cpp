#include <bits/stdc++.h>
using namespace std;

int x, y, k, m, ans = INT_MAX;
bool vis[101][101];

struct pails {
  int a, b, c;
};

void bfs(int u, int v) {
  queue<pails> q;
  q.push({u,v,0});
  while(!q.empty()) {
    int r = q.front().a;
    int c = q.front().b;
    int t = q.front().c;
    q.pop();

    if(vis[r][c] || t > k) {
      continue;
    }

    vis[r][c] = 1;
    ans = min(ans, abs(m-r-c));

    q.push({x,c,t+1});
    q.push({r,y,t+1});
    q.push({0,c,t+1});
    q.push({r,0,t+1});

    int tr = r;
    int tc = c;

    int dec = min(x-r, c);
    tc -= dec;
    tr += dec;
    q.push({tr, tc, t+1});

    tr = r;
    tc = c;

    dec = min(y-c, r);
    tr -= dec;
    tc += dec;
    q.push({tr, tc, t+1});
  }
}

int main() {
  ifstream cin("pails.in");
  ofstream cout("pails.out");
  
  cin>>x>>y>>k>>m;

  bfs(0,0);

  cout<<ans<<endl;
  
  return 0;
} 

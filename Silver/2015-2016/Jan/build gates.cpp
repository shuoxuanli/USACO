#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int n, ans = -1, dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int x = 2000, y = 2000, l = 2000, b = 2000, r = 2000, t = 2000;
bool vis[4001][4001], fence[4001][4001];
string s;

void bfs(int y, int x) {
  queue<pi> q;
  q.push(make_pair(y,x));
  while(!q.empty()) {
    int R = q.front().first;
    int C = q.front().second;
    q.pop();

    if(R < t || R > b || C < l || C > r || vis[R][C] || fence[R][C]) {
      continue;
    }

    vis[R][C] = 1;
    for(int i = 0; i < 4; i++) {
      q.push(make_pair(R + dy[i], C + dx[i]));
    }
  }
}

int main() {

  ifstream cin("gates.in");
  ofstream cout("gates.out");
  
  cin>>n;
  cin>>s;

  fence[y][x] = 1;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'N') {
      y--;
      fence[y][x] = 1;
      y--;
      fence[y][x] = 1;
      t = min(t, y);
    }
    else if(s[i] == 'S') {
      y++;
      fence[y][x] = 1;
      y++;
      fence[y][x] = 1;
      b = max(b, y);
    }
    else if(s[i] == 'W') {
      x--;
      fence[y][x] = 1;
      x--;
      fence[y][x] = 1;
      l = min(l, x);
    } else {
      x++;
      fence[y][x] = 1;
      x++;
      fence[y][x] = 1;
      r = max(r, x);
    }
  }

  t--; b++; r++; l--;

  for(int i = t; i <= b; i++) {
    for(int j = l; j <= r; j++) {
      if(!vis[i][j] && !fence[i][j]) {
        bfs(i, j);
        ans++;
      }
    }
  }

  cout<<ans<<endl;
  return 0;
} 

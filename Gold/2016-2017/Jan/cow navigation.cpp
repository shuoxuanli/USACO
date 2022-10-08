#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int INF = 0x3f3f3f3f;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int n;
string s[21];
int dis[21][21][21][21][4][4];

bool ok(int r, int c, int i) {
  if(r == 0 && c == n-1)
    return false;
  r += d[i][0], c += d[i][1];
  return r >= 0 && c >= 0 && r < n && c < n && s[r][c] != 'H';
}

bool chk(array<int, 6> &a) {
  return dis[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]] == INF;
}

int main() {
  ifstream cin("cownav.in");
  ofstream cout("cownav.out");
  
  cin>>n;
  for(int i = 0; i < n; i++) 
    cin>>s[i];
  
  memset(dis, 0x3f, sizeof(dis));
  queue<array<int, 6>> q;
  q.push({n-1, 0, n-1, 0, 0, 3});
  dis[n-1][0][n-1][0][0][3] = 0;
  while(!q.empty()) {
    auto a = q.front();
    q.pop();
  
    auto b = a;
    for(auto i : {0, 2}) {
      if(ok(a[i], a[i+1], a[i/2 + 4])) {
        b[i] += d[a[i/2 + 4]][0];
        b[i+1] += d[a[i/2 + 4]][1];
      }
    }
    if(chk(b)) {
      q.push(b);
      dis[b[0]][b[1]][b[2]][b[3]][b[4]][b[5]] = 
      dis[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]] + 1;
    }
  
    for(auto i : {1, -1}) {
      b = a;
      for(int j = 4; j < 6; j++) {
        if(a[2*(j-4)] != 0 || a[2*(j-4)+1] != n-1) {
          b[j] = (b[j] + i + 4) % 4;
        }
      }
      if(chk(b)) {
        q.push(b);
        dis[b[0]][b[1]][b[2]][b[3]][b[4]][b[5]] = 
        dis[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]] + 1;
      }
    }
  }
  
  int ans = INF;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      ans = min(ans, dis[0][n-1][0][n-1][i][j]);
    }
  }
  cout<<ans<<endl;
  return 0;
}

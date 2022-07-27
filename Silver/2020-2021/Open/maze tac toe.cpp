#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

struct pt {
  int x, y, b;
};

int n, pow3[9];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 3}, {0, -3}};
string s[25];
set<int> ans;
bool vis[25][75][20000];

bool eval(string b, int x, int y) {
  char g[3][3];
  for(int i = 0; i < 9; i++)
    g[i/3][i%3] = b[i];
  string t = "";
  for(int i = 0; i < 3; i++)
    t += g[x][i];
  if(t == "211" || t == "112")
    return 1;
  t = "";
  for(int i = 0; i < 3; i++)
    t += g[i][y];
  if(t == "211" || t == "112")
    return 1;
  t = "";
  for(int i = 0, j = 0; i < 3 && j < 3; i++, j++)
    t += g[i][j];
  if(t == "211" || t == "112")
    return 1;
  t = "";
  for(int i = 2, j = 0; i >= 0 && j < 3; i--, j++)
    t += g[i][j];
  if(t == "211" || t == "112")
    return 1;
  return 0;
}

string ter(int b) {
  string res = "";
  int i = 8;
  while(i >= 0) {
    int j = 0;
    while(b >= pow3[i]) 
      b -= pow3[i], j++;
    res += char(j+'0');
    i--;
  }
  reverse(res.begin(), res.end());
  return res;
}

int dec(string b) {
  int res = 0;
  for(int i = 0; i < 9; i++)
    res += (b[i]-'0')*pow3[i];
  return res;
}

void bfs(int x, int y) {
  queue<pt> q;
  q.push({x, y, 0});
  while(!q.empty()) {
    int r = q.front().x;
    int c = q.front().y;
    int b = q.front().b;
    q.pop();
    if(r < 0 || c < 0 || r >= n || c >= 3*n)
      continue;
    if(s[r][c] == '#' || vis[r][c][b])
      continue;
    vis[r][c][b] = 1;
    if(s[r][c] != '.' && s[r][c] != 'B') {
      int r2 = s[r][c+1]-'0'-1;
      int c2 = s[r][c+2]-'0'-1;
      string tmp = ter(b);
      if(tmp[r2*3+c2] == '0') {
        tmp[r2*3+c2] = s[r][c] == 'O' ? '1' : '2';
        b = dec(tmp);
        if(eval(tmp, r2, c2)) {
          vis[r][c][b] = 1;
          ans.insert(b);
          continue;
        }
      }
    }
    for(int i = 0; i < 4; i++) {
      int nr = r + d[i][0];
      int nc = c + d[i][1];
      q.push({nr, nc, b}); 
    }
  }
}

int main() {
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>s[i];
  pow3[0] = 1;
  for(int i = 1; i < 9; i++)
    pow3[i] = pow3[i-1]*3;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3*n; j += 3) {
      if(s[i][j] == 'B') {
        bfs(i, j);
        break;
      }
    }
  }
  cout<<sz(ans)<<endl;
  return 0;
}

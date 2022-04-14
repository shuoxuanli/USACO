#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

const int maxN = 1001;
int n, area = 0, perimeter = INT_MAX, icecream[maxN][maxN], dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
bool vis[maxN][maxN];

void bfs(int x, int y) {
  int tmpa = 0;
  int tmpp = 0;
  queue<pi> q;
  q.push({x,y});
  while(!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop(); 
    if(r < 1 || r > n || c < 1 || c > n || icecream[r][c] == 0) {
      tmpp++;
      continue;
    }
    else if(vis[r][c]) {
      continue;
    }
    
    vis[r][c] = 1;
    tmpa++;
    for(int i = 0; i < 4; i++) {
      q.push(make_pair(r+dx[i], c + dy[i]));
    }
  }
  if(tmpa > area) {
    area = tmpa;
    perimeter = tmpp;
  }
  else if(tmpa == area) {
    perimeter = min(perimeter, tmpp);
  }
}


int main() {
  ifstream cin("perimeter.in");
  ofstream cout("perimeter.out");

  cin>>n;

  for(int i = 1; i <= n; i++) {
    string s;
    cin>>s;
    for(int j = 0; j < s.length(); j++) {
      if(s[j] == '#') {
        icecream[i][j+1] = 1;
      } else {
        icecream[i][j+1] = 0;
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(icecream[i][j] == 1) {
        bfs(i,j);
      }
    }
  }

  cout<<area<<" "<<perimeter<<endl;
} 

/*
 ID: shuoxua2
 PROG: castle
 LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int w, h, n;

vector<int> gfill;
vector<int> rsize;
vector<vector<int>> g;

int s, mxn = 0;

inline int idx(int r, int c) {
  return r * w + c;
}

void bfs(int index, int color) {
  if (gfill[index] != 0) {
    return;
  }
  queue<int> q;
  q.push(index);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    if (gfill[node] != 0) {
      continue;
    }
    
    gfill[node] = color;
    ++s;

    for (int node2 : g[node]) {
      if (gfill[node2] == 0) {
        q.push(node2);
      }
    }
  }
}

int main() {  
  ifstream cin("castle.in");
  ofstream cout("castle.out");
  
  cin >> w >> h;
  n = w * h;

  gfill = vector<int>(n + 2, 0);
  rsize = vector<int>(n + 2, 0);
  g.resize(n);
  
  for (int row = 0; row < h; ++row) {
    for (int col = 0; col < w; ++col) {
      int v; cin >> v;
      if ((v & 1) == 0) {
        g[idx(row,col)].push_back(idx(row,col-1));
        g[idx(row,col-1)].push_back(idx(row,col));
      }
      v = v >> 1;
      if ((v & 1) == 0) {
        g[idx(row,col)].push_back(idx(row-1,col));
        g[idx(row-1,col)].push_back(idx(row,col));
      }
    }
  }

  
  int cnt = 1;
  for (int i = 0; i < n; ++i) {
    if (gfill[i] == 0) {
      s = 0;
      bfs(i, cnt);
      rsize[cnt] = s;
      mxn = max(mxn, s);
      ++cnt;
    }
  }
  
  cout << --cnt << endl;
  cout << mxn << endl;
  
  int m = 0, r = -1, c = -1;
  string d = "";
  
  for (int col = 0; col < w; ++col) {
    for (int row = h - 1; row >= 0; --row) {
      if (row > 0) {
        int p1 = idx(row, col), p2 = idx(row-1, col);
        if (gfill[p1] != gfill[p2]) {
          if (rsize[gfill[p1]] + rsize[gfill[p2]] > m) {
            m = rsize[gfill[p1]] + rsize[gfill[p2]];
            r = row;
            c = col;
            d = "N";
          }
        }
      }
      if (col < w - 1) {
        int p1 = idx(row, col), p2 = idx(row, col+1);
        if (gfill[p1] != gfill[p2]) {
          if (rsize[gfill[p1]] + rsize[gfill[p2]] > m) {
             m = rsize[gfill[p1]] + rsize[gfill[p2]];
            r = row;
            c = col;
            d = "E";
          }
        }
      }
    }
  }
  
  cout << m << endl;
  cout << r+1 << " " << c+1 << " " << d << endl;
  
  return 0;
}

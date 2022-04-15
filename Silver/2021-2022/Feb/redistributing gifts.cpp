#include <bits/stdc++.h>
using namespace std;

int p[501][501], g[501][501];

int main() {
  int n;
  cin>>n;

  for(int i = 1; i <= n; i++) {
    bool swap = 1;
    for(int j = 1; j <= n; j++) {
     cin>>p[i][j];
      if(swap) {
        g[p[i][j]][i] = 1;
      }
      if(p[i][j] == i) {
        swap = 0;
      }
    }
  } 
  
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(g[i][k] && g[k][j]) {
          g[i][j] = 1;
        }
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(g[i][p[i][j]]) {
        cout<<p[i][j]<<endl;
        break;
      }
    }
  }
  return 0;
} 

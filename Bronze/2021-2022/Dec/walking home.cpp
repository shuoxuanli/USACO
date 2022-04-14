#include<bits/stdc++.h>
using namespace std;

string a[51];

int main() {
  int t;
  cin>>t;

  while(t>0) {
    t--;
    int n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++) {
      cin>>a[i];
    }

    int ans = 0;
    if(k >= 1) {
      int can = 1;
      for(int i = 1; i <= n; i++) {
        if(a[1][i-1] != '.') can = 0;
      }
      for(int i = 1; i <= n; i++) {
        if(a[i][n-1] != '.') can = 0;
      }
      if(can) ans++;
      can = 1;
      for(int i = 1; i <= n; i++) {
        if(a[i][0] != '.') can = 0;
      }
      for(int i = 1; i <= n; i++) {
        if(a[n][i-1] != '.') can = 0;
      }
      if(can) ans++;
    }
    if(k >= 2) {
      for(int j = 2; j < n; j++) {
        int can = 1;
        for(int i = 1; i <= j; i++) {
          if(a[i][0] != '.') can = 0;
        }
        for(int i = 1; i <= n; i++) {
          if(a[j][i-1] != '.') can = 0;
        }
        for(int i = j; i <= n; i++) {
          if(a[i][n-1] != '.') can = 0;
        }
        if(can) ans++;
        can = 1;
        for(int i = 1; i <= j; i++) {
          if(a[1][i-1] != '.') can = 0;
        }
        for(int i = 1; i <= n; i++) {
          if(a[i][j-1] != '.') can = 0;
        }
        for(int i = j; i <= n; i++) {
          if(a[n][i-1] != '.') can = 0;
        }
        if(can) ans++;
      }
    }
    if(k >= 3) {
      for(int x = 2; x < n; x++) {
        for(int y = 2; y < n; y++) {
          int can = 1;
          for(int i = 1; i <= x; i++) {
            if(a[i][0] != '.') can = 0;
          }
          for(int i = 1; i <= y; i++) {
            if(a[x][i-1] != '.') can = 0;
          }
          for(int i = x; i <= n; i++) {
            if(a[i][y-1] != '.') can = 0;
          }
          for(int i = y; i <= n; i++) {
            if(a[n][i-1] != '.') can = 0;
          }
          if(can) ans ++;
          can = 1;
          for(int i = 1; i <= x; i++) {
            if(a[1][i-1] != '.') can = 0;
          }
          for(int i = 1; i <= y; i++) {
            if(a[i][x-1] != '.') can = 0;
          }
          for(int i = x; i <= n; i++) {
            if(a[y][i-1] != '.') can = 0;
          }
          for(int i = y; i <= n; i++) {
            if(a[i][n-1] != '.') can = 0;
          }
          if(can) ans ++;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
} 

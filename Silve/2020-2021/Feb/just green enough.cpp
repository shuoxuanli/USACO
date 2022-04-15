#include <bits/stdc++.h>
using namespace std;

#define ll long long
int grid[501][501];

int main() {
  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin>>grid[i][j];
    }
  }

  ll ans = 0;
  for(int i = 0; i < n; i++) {
    int mink[501];
    memset(mink, 0x7f, sizeof(mink));
    for(int j = i; j < n; j++) {
      int l = -1, cnt = 0;
      for(int r = 0; r < n; r++) {
        mink[r] = min(grid[j][r], mink[r]);
        if(mink[r] < 100) {
          l = r;
          cnt = 0;
        }
        else if(mink[r] == 100) {
          cnt = r-l;
        }
        ans += cnt;
      }
    }
  }

  cout<<ans<<endl;
  return 0;
} 

#include<bits/stdc++.h>
using namespace std;

bool grid[10][10];

int main() {
  freopen("cowtip.in", "r", stdin);
  freopen("cowtip.out", "w", stdout);

  int n;
  cin>>n;

  string s; 
  for(int i = 0; i < n; i++) {
    cin>>s;
    for(int j = 0; j < n; j++) {
      grid[i][j] = s[j] - '0';
    }
  }

  int ans = 0;
  for(int i = n-1; i >= 0; i--) {
    for(int j = n-1; j >= 0; j--) {
      if(grid[i][j]) {
        ans++;
        for(int k = 0; k <= i; k++) {
          for(int m = 0; m <= j; m++) {
            grid[k][m] = !grid[k][m];
          }     
        }
      }
    }
  }

  cout<<ans<<endl;
  return 0;
}

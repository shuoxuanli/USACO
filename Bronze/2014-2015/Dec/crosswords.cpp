#include <bits/stdc++.h>
using namespace std;

char grid[60][60];
int ans[50*50][2];

int main() {
  freopen("crosswords.in", "r", stdin);
  freopen("crosswords.out", "w", stdout);

  int n, m;
  cin>>n>>m;

  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin>>grid[i][j];
    }
  }

  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(j==1 && j <= m-2 && grid[i][j] == '.' && grid[i][j+1] == '.' && grid[i][j+2] == '.') {
        ans[cnt][0] = i;
        ans[cnt][1] = j;
        cnt++;
        continue;
      }

      if(j != 1 && j <= m-2 && grid[i][j-1] == '#' && grid[i][j] == '.' && grid[i][j+1] == '.' && grid[i][j+2] == '.') {
        ans[cnt][0] = i;
        ans[cnt][1] = j;
        cnt++;
        continue;
      }

      if(i==1 && i <= n-2 && grid[i][j] == '.' && grid[i+1][j] == '.' && grid[i+2][j] == '.') {
        ans[cnt][0] = i;
        ans[cnt][1] = j;
        cnt++;
        continue;
      }

      if(i != 1 && i <= n-2 && grid[i-1][j] == '#' && grid[i][j] == '.' && grid[i+1][j] == '.' && grid[i+2][j] == '.') {
        ans[cnt][0] = i;
        ans[cnt][1] = j;
        cnt++;
        continue;
      }
    }
  }

  cout<<cnt<<endl;
  for(int i = 0; i < cnt; i++) {
    cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
  }
  return 0;
	
} 

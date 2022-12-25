#include<bits/stdc++.h>
using namespace std;

int n, a[301], f[301][301];

int main() {
  cin>>n;

  for(int i = 1; i <= n; i++) {
    cin>>a[i];
    f[i][i] = 1;
  }

  for(int i = n-1; i > 0; i--) {
    for(int j = i+1; j <= n; j++) {
      f[i][j] = f[i][j-1] + (a[i]!=a[j]);
      for(int k = i; k < j; k++) {
        f[i][j] = min(f[i][j], f[i][k]+f[k+1][j]);
      }
    }
  }

  cout<<f[1][n]<<endl;
  return 0;
} 

#include <bits/stdc++.h>
using namespace std;

int n, g[1001][1001], ans = 0;

int main() {
  cin>>n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin>>g[i][j];
    }
  }

  int tmp = 0;
  for(int i = 0; i < n; i++) {
    int odd = 0, even = 0;
    for(int j = 0; j < n; j++) {
      if(j%2==0) even += g[j][i];
      else odd += g[j][i];
    }
    tmp += (odd>even) ? odd : even;
  }

  ans = max(ans, tmp);

  tmp = 0;
  for(int i = 0; i < n; i++) {
    int odd = 0, even = 0;
    for(int j = 0; j < n; j++) {
      if(j%2==0) even += g[i][j];
      else odd += g[i][j];
    }
    tmp += (odd>even) ? odd : even;
  }

  ans = max(tmp, ans);

  cout<<ans<<endl;
} 

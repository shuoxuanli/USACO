#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, m, k;
ll a[50][50], p[200005][26], dp[200005][26][2];
string s;

int main() {
  ifstream cin("cowmbat.in");
  ofstream cout("cowmbat.out");
  
  cin>>n>>m>>k>>s;
  
  memset(a, 0x3f, sizeof(a));
  for(int i = 0; i < m; i++) 
    for(int j = 0; j < m; j++) 
      cin>>a[i][j];
  for(int k = 0; k < m; k++) {
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < m; j++) {
        a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
      }	
    }
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < m; j++) {
      p[i][j] = p[i-1][j] + a[s[i-1]-'a'][j];
    }
  } 
  
  memset(dp, 0x3f, sizeof(dp));
  for(int i = 0; i < m; i++)
    dp[1][i][0] = 0;
  
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < m; j++) {
      for(int l = 0; l < m; l++) {
        if(j == l) {
          dp[i+k][l][1] = min(dp[i+k][l][1], dp[i][j][0]+p[i+k-1][j]-p[i-1][j]);
          dp[i+1][l][1] = min(dp[i+1][l][1], dp[i][j][1]+p[i][j]-p[i-1][j]);
        } else {
          dp[i+k][l][0] = min(dp[i+k][l][0], dp[i][j][0]+p[i+k-1][j]-p[i-1][j]);
          dp[i+1][l][0] = min(dp[i+1][l][0], dp[i][j][1]+p[i][j]-p[i-1][j]);
        }
      }
    }
  }
  
  ll ans = LLONG_MAX;
  for(int i = 0; i < m; i++) 
    ans = min(ans, min(dp[n+1][i][0], dp[n+1][i][1]));
  cout<<ans<<endl;
  return 0;
}

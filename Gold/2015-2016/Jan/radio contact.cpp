#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
ll n, m, dp[1001][1001];
pll f, b, mf[1001], mb[1001];

ll dis(pll a, pll b) {
  int dx = (a.first - b.first);
  int dy = (a.second - b.second);
  return dx*dx + dy*dy;
}

int main() {
  ifstream cin("radio.in");
  ofstream cout("radio.out");
  
  cin>>n>>m;
  cin>>f.first>>f.second;
  cin>>b.first>>b.second;

  string s;
  cin>>s;

  mf[0] = f;
  for(int i = 1; i <= n; i++) {
    if(s[i-1] == 'E') {
      mf[i].first = mf[i-1].first + 1;
      mf[i].second = mf[i-1].second;
    }
    if(s[i-1] == 'W') {
      mf[i].first = mf[i-1].first - 1;
      mf[i].second = mf[i-1].second;
    }
    if(s[i-1] == 'N') {
      mf[i].first = mf[i-1].first;
      mf[i].second = mf[i-1].second + 1;
    }
    if(s[i-1] == 'S') {
      mf[i].first = mf[i-1].first;
      mf[i].second = mf[i-1].second - 1;
    }
  }

  cin>>s;
  
  mb[0] = b;
  for(int i = 1; i <= m; i++) {
    if(s[i-1] == 'E') {
      mb[i].first = mb[i-1].first + 1;
      mb[i].second = mb[i-1].second;
    }
    if(s[i-1] == 'W') {
      mb[i].first = mb[i-1].first - 1;
      mb[i].second = mb[i-1].second;
    }
    if(s[i-1] == 'N') {
      mb[i].first = mb[i-1].first;
      mb[i].second = mb[i-1].second + 1;
    }
    if(s[i-1] == 'S') {
      mb[i].first = mb[i-1].first;
      mb[i].second = mb[i-1].second - 1;
    }
  }

  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      dp[i][j] = 1e10;
    }
  }

  dp[0][0] = 0; ll e;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      e = dis(mf[i], mb[j]);
      if(i > 0 && j > 0) {
        dp[i][j] = min(dp[i][j], dp[i-1][j-1] + e);
      }
      if(i > 0) {
        dp[i][j] = min(dp[i][j], dp[i-1][j] + e);
      }
      if(j > 0) {
        dp[i][j] = min(dp[i][j], dp[i][j-1] + e);
      }
    }
  }

  cout<<dp[n][m]<<endl;
  return 0;
} 

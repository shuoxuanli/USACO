#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e3+5, MOD = 1e9+7;
int t, n, lasta[maxN], lastb[maxN], dp[maxN][maxN];
string bs, es;

int solve() {
  vector<char> a, b;
  a.push_back('0');
  b.push_back('0');
  int az = 0, bz = 0;
  for(int i = 0; i < n; i++) {
    if(bs[i] == '0') az = i;
    if(es[i] == '0') bz = i;
  }

  for(int i = az; i < n; i++) {
    if(bs[i] != '1') a.push_back(bs[i]);
  } 

  for(int i = bz; i < n; i++) {
    if(es[i] != '1') b.push_back(es[i]);
  }
  
  int m = a.size()-1, k = b.size()-1;
  
  lasta[0] = lastb[0] = 0;
  for(int i = 1; i <= m; i++) {
    lasta[i] = (a[i]=='+') ? i : lasta[i-1];
  }

  for(int i = 1; i <= k; i++) {
    lastb[i] = (b[i]=='+') ? i : lastb[i-1];
  }

  for(int i = 0; i <= m; i++) {
    for(int j = 0; j <= k; j++) {
      if(i == 0 || j == 0)
        dp[i][j] = 1;
      else if(a[i] == '+' && b[j] == '+')
        dp[i][j] = ((dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%MOD+MOD)%MOD;
      else if(a[i] == '+' || b[j] == '+') 
        dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
      else {
        if(!lasta[i] && !lastb[j]) dp[i][j] = 1;
        else if(!lasta[i]) dp[i][j] = dp[i][lastb[j]];
        else if(!lastb[j]) dp[i][j] = dp[lasta[i]][j];
        else dp[i][j] = ((dp[lasta[i]][j]+dp[i][lastb[j]]-dp[lasta[i]][lastb[j]])%MOD+MOD)%MOD;
      }
    }
  }
  return dp[m][k];
}

int main() {
  cin>>t;
  while(t--) {
    cin>>n>>bs>>es;
    cout<<solve()<<endl;
  }
  return 0;
} 

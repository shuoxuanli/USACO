#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;
ll n, m, k, dp[5001], l[5001];
map<char, int> mp;

struct word {
  int s, c;
} w[5001];

ll binpow(ll x, int exp) {
  ll ret = 1;
  x %= MOD;
  while(exp) {
    if(exp&1) ret = ret*x%MOD;
    x = x*x%MOD;
    exp >>= 1;
  }
  return ret;
}

int main() {
  ifstream cin("poetry.in");
  ofstream cout("poetry.out");
  
  cin>>n>>m>>k;

  for(int i = 1; i <= n; i++) {
    cin>>w[i].s>>w[i].c;
  }
  
  for(int i = 1; i <= m; i++) {
    char c; cin>>c;
    mp[c]++;
  }

  dp[0] = 1;
  for(int i = 0; i <= k; i++) {
    for(int j = 1; j <= n; j++) { 
      if(i+w[j].s > k) continue;
      if(i+w[j].s == k) l[w[j].c] = (l[w[j].c] + dp[i])%MOD;
      else dp[i+w[j].s] = (dp[i+w[j].s] + dp[i])%MOD;
    }
  }
  
  ll ans = 1;
  for(auto & m : mp) {
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
      if(l[i] == 0) continue;
      sum = (sum + binpow(l[i], m.second))%MOD;
    }
    ans = ans * sum % MOD;
  }

  cout<<ans<<endl;
  return 0;
} 

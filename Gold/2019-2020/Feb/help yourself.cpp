#include <bits/stdc++.h>
using namespace std;

# define ll long long
const int maxN = 1e5+1, MOD = 1e9+7;

struct seg {
  int l, r;
} a[maxN];

int n, prefix[2*maxN];

ll binpow(ll b, ll exp) {
  b %= MOD;
  ll res = 1;
  while(exp) {
    if(exp&1) 
      res = res*b%MOD;
    b = b*b%MOD;
    exp >>= 1;
  }
  return res;
}

int main() {
  ifstream cin("help.in");
  ofstream cout("help.out");
  
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>a[i].l>>a[i].r;
    prefix[a[i].l]++;
    prefix[a[i].r]--;
  }

  for(int i = 1; i <= 2*n; i++) {
    prefix[i] += prefix[i-1];
  }
  
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans = (ans + binpow(2ll, n-1-prefix[a[i].l-1]))%MOD;
  }
  
  cout<<ans<<endl;
  return 0;
} 

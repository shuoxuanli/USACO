#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n, k, m;

bool check(ll x) {
  ll K = k;
  ll g = 0;
  while(K > 0 && g < n) {
    ll y = (n-g)/x;
    if(y < m) {
      ll rem = (n-g + m-1)/m;
      return rem <= K;
    }
    ll milk = n - x*y;
    ll day = (milk-g)/y +1;
    day = min(day, K);
    K -= day;
    g += day*y;
  }

  return g >= n;
}

int main() {
  ifstream cin("loan.in");
  ofstream cout("loan.out");

  cin>>n>>k>>m;

  ll ans  = 0, l = 1, r = n;
  while(l <= r) {
    ll mid = (l+r)/2;
    if(check(mid)) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }

  cout<<ans<<endl;
  return 0;
} 

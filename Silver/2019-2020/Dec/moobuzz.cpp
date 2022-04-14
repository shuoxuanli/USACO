#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n;
bool check(ll val) {
  int tmp = val;
  val -= tmp/3;
  val -= tmp/5;
  val += tmp/15;
  return val >= n;
}

int main() {
  freopen("moobuzz.in", "r", stdin);
  freopen("moobuzz.out", "w", stdout);

  cin>>n;

  ll l = 1, r = pow(2,62), ans = 0;;
  while(l<=r) {
    ll mid = (l+r)/2;
    if(check(mid)) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  cout<<ans<<endl;
  return 0;
} 

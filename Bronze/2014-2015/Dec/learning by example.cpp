#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
  freopen("learning.in", "r", stdin);
  freopen("learning.out", "w", stdout);

  ll n, a, b;
  cin>>n>>a>>b;
  vector<pll> v;
  for(ll i=0; i<n; i++) {
    char buf[100];
    ll w;
    cin>>buf>>w;
    v.pb(mp(w, buf[0]=='S' ? 1 : 0));
  }
  ll INF = ll(1000)*1000*1000*1000;
  v.pb(mp(-INF, 0));
  v.pb(mp(INF, 0));
  sort(v.begin(), v.end());

  ll ans = 0;
  for(ll i = 0; i < v.size()-1; i++) {
    ll s = v[i].x;
    ll e = v[i+1].x;
    ll m = (s+e)/2;

    if(v[i].y==1) {
      ll s2 = max(a, s+1);
      ll e2 = min(b, m);
      if(e2 >= s2) {
        ans += e2-s2+1;
      }
    }
    if(v[i+1].y==1) {
      ll s2 = max(a, m+1);
      ll e2 = min(b, e);
      if(e2 >= s2) {
        ans += e2-s2+1;
      }
    }
    if(v[i+1].y==1 && v[i].y==0 && (s%2)==(e%2) && a<=m && m<=b) {
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int P = 9973, MOD = 1e9+7;

int n, m;
string a[505], b[505];
ll base[505], pa[505][505], pb[505][505];

int main() {
  ifstream cin("cownomics.in");
  ofstream cout("cownomics.out");
  
  cin>>n>>m;
  for(int i = 1; i <= n; i++)
    cin>>a[i];
  for(int i = 1; i <= n; i++)
    cin>>b[i];
  
  base[0] = 1;
  for(int i = 1; i < m; i++)
    base[i] = base[i-1] * P % MOD;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      pa[i][j] = (pa[i][j-1] * P % MOD + a[i][j-1]) % MOD;
      pb[i][j] = (pb[i][j-1] * P % MOD + b[i][j-1]) % MOD;
    }
  }
  
  auto geta = [&](int i, int l, int r) {
    return (pa[i][r] - (base[r - l + 1] * pa[i][l-1] % MOD) + MOD) % MOD;
  };
  
  auto getb = [&](int i, int l, int r) {
    return (pb[i][r] - (base[r - l + 1] * pb[i][l-1] % MOD) + MOD) % MOD;
  };
  
  auto chk = [&](int l, int r) {
    set<ll> sa, sb;
    for(int i = 1; i <= n; i++) {
      sa.insert(geta(i, l, r));
      sb.insert(getb(i, l, r));
    }
  
    for(auto x : sa) {
      if(sb.count(x))
        return false;
    }
    return true;
  };
  
  int ans = m;
  for(int i = 1; i <= m; i++) {
    bool fl = false;
    int l = i, r = m, cur = m;
    while(l <= r) {
      int mid = (l+r)/2;
      if(chk(i, mid)) {
        r = mid - 1;
        cur = mid;
        fl = true;
      } else {
        l = mid + 1;
      }
    }
  
    if(fl) ans = min(ans, cur - i + 1);
  }
  
  cout<<ans<<'\n';
  return 0;
}

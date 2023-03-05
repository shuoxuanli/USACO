#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int t, n;
ll m, k, a[101], b[101], c[101];

void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i] >> c[i];

  auto chk = [&](ll x) {
    ll l = 0, r = x;
    while (l <= r) {
      ll mid = (l + r) / 2;
      bool na = false, nb = false;
      for (int i = 0; i < n; i++) {
        if (a[i] * (m - mid) + b[i] * (k - x + mid) > c[i]) {
          na |= a[i] >= b[i];
          nb |= a[i] <= b[i];
        }
      }
      if (mid > m - 1) nb = true, na = false;
      if (x - mid > k - 1) na = true, nb = false;
      if (na == nb) return !na;
      na ? (l = mid + 1) : (r = mid - 1);
    }
    return false;
  };

  ll l = 0, r = m + k - 2;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (chk(mid))
      r = mid;
    else
      l = mid + 1;
  }

  cout << l << '\n';
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

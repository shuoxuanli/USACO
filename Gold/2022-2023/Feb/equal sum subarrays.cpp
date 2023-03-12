#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n;
ll a[505], sum[505], ans[505][505];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i-1] + a[i];
  }

  set<ll> s;
  auto upd = [&](int l, int r, ll val) {
    auto hi = s.lower_bound(val);
    auto lo = s.upper_bound(val);
    if (hi != s.end()) ans[l][r] = min(ans[l][r], *hi - val);
    if (lo != s.begin()) ans[l][r] = min(ans[l][r], val - *(--lo));

    vector<ll> tmp;
    if (r == n && s.count(sum[l-1]))
      s.erase(sum[l-1]), tmp.push_back(sum[l-1]);
    if (l == 1 && s.count(sum[n] - sum[r]))
      s.erase(sum[n] - sum[r]), tmp.push_back(sum[n] - sum[r]);

    auto hi2 = s.lower_bound(-val);
    auto lo2 = s.upper_bound(-val);
    if (hi2 != s.end()) ans[l][r] = min(ans[l][r], *hi2 + val);
    if (lo2 != s.begin()) ans[l][r] = min(ans[l][r], -val - *(--lo2));

    for (ll x : tmp) s.insert(x);
  };

  memset(ans, 0x7f, sizeof(ans));
  for (int i = 1; i <= n; i++) {
    for (int j = i-1; j >= 1; j--)
      s.insert(sum[i-1] - sum[j-1]);
    for (int j = i; j <= n; j++)
      upd(i, j, sum[j] - sum[i-1]);
  }

  s.clear();
  for (int i = n; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++)
      s.insert(sum[j] - sum[i]);
    for (int j = i; j >= 1; j--)
      upd(j, i, sum[i] - sum[j-1]);
  }

  for (int i = 1; i <= n; i++) {
    ll now = abs(a[i]);
    for (int j = 1; j <= i; j++) {
      for (int k = i; k <= n; k++) {
        now = min(now, ans[j][k]);
      }
    }
    cout << now << '\n';
  }
  return 0;
}

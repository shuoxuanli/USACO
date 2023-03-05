#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

ll n, t;

int main() {
  cin >> n >> t;

  ll ans = 0, st = 0, ed = 0;
  for (int i = 0; i < n; i++) {
    ll d, b;
    cin >> d >> b;
    if (d > ed) {
      ans += ed - st;
      st = d;
      ed = d + b;
    } else {
      ed += b;
    }
  }
  ed = min(ed, t + 1);
  ans += ed - st;

  cout << ans << '\n';
  return 0;
}

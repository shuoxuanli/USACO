#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

ll n, k, d[100001];

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> d[i];

  ll ans = n + k;
  for (int i = 1; i < n; i++) {
    ans += min(d[i] - d[i-1] - 1, k);
  }

  cout << ans << '\n';
  return 0;
}

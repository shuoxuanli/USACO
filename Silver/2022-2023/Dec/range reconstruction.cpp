#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, a[305][305], ans[305];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
      cin >> a[i][j];

  for (int i = 1; i < n; i++) {
    bool ok = true;
    ans[i] = ans[i-1] + a[i-1][i];
    int mx = ans[i], mn = ans[i];
    for (int j = i-1; j >= 0; j--) {
      mn = min(mn, ans[j]);
      mx = max(mx, ans[j]);
      ok &= mx - mn == a[j][i];
    }
    if (!ok) ans[i] = ans[i-1] - a[i-1][i];
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}

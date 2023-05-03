#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int t, n, k, a[100001], b[100001];

int main() {
  cin >> t >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];

  if (t == 1) {
    int ans = 0;
    vector<int> v1(2, INT_MAX), v2(2, INT_MAX);
    for (int i = 0, j = 0; i < n; i++) {
      v1[i & 1] = min(v1[i & 1], b[i]);
      if (i == 0 || i == n - 1 || a[i + 1] - a[i - 1] <= k) {
        v2[i & 1] = min(v2[i & 1], b[i]);
      }
      if (i == n - 1 || a[i + 1] - a[i] > k) {
        int take = min(v1[i & 1], v2[(i & 1) ^ 1]);
        ans += take * ((i - j + 1) & 1);
        v1[0] = v1[1] = INT_MAX;
        v2[0] = v2[1] = INT_MAX;
        j = i + 1;
      }
    }
    cout << ans << '\n';
  } else {
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(2));
    for (int i = 0, j = 0, l = 0; i < n; i++) {
      while (a[i] - a[j] > k) j++;
      if (i > l) dp[i] = dp[i - 1];
      if (i == l || i == n - 1 || a[i + 1] - a[i] > k || a[i + 1] - a[i - 1] <= k || (i - l + 1) & 1) {
        dp[i][1] = max(dp[i][1], (j > l ? dp[j - 1][0] : 0) + b[i]);
      }
      if (i == l || i == n - 1 || a[i + 1] - a[i] > k || a[i + 1] - a[i - 1] <= k || !((i - l + 1) & 1)) {
        dp[i][0] = max(dp[i][0], (j > l ? dp[j - 1][1] : INT_MIN) + b[i]);
      }
      if (i == n - 1 || a[i + 1] - a[i] > k) {
        ans += dp[i][(i - l + 1) & 1];
        l = i + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int MOD = 1E9 + 7;
int n, a[105], dp[105][1001];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int mn = *min_element(a + 1, a + n + 1);
  if (n % 2 == 0) mn = 0;

  int ans = 0;
  for (int k = 0; k <= mn; k++) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= 1000; i++) {
      dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= a[i] - k; j++) {
        dp[i][j] = (dp[i][j] + dp[i - 1][a[i] - k - j]) % MOD;
      }
      for (int j = 1; j <= 1000; j++) {
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
      }
    }
    ans = (ans + dp[n][0]) % MOD;
  }

  cout << ans << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 2E5 + 1;
int a[N];
string s, b = "bessie";
pair<int, int> dp[N][6];

int main() {
  cin >> s;
  for (int i = 1; i <= sz(s); i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= sz(s); i++) {
    for (int j = 0; j < 6; j++) {
      dp[i][j] = {-1E9, -1E9};
    }
  }

  dp[0][5] = {0, 0};
  for (int i = 1; i <= sz(s); i++) {
    for (int j = 0; j < 6; j++) {
      if (s[i - 1] == b[j]) {
        auto x = dp[i - 1][(j + 5) % 6];
        x.first += j == 5;
        dp[i][j] = max(dp[i][j], x);
      }
      dp[i][5] = max(dp[i][5], dp[i - 1][j]);
      dp[i][j] = max(dp[i][j], make_pair(dp[i - 1][j].first, dp[i - 1][j].second - a[i]));
    }
  }

  pair<int, int> ans{};
  for (int i = 1; i <= sz(s); i++) {
    ans = max(ans, *max_element(dp[i], dp[i] + 6));
  }
  cout << ans.first << '\n';
  cout << -ans.second << '\n';
  return 0;
}

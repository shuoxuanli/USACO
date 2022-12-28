#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

struct cow {
  int p, c, x;
} w[2005];

int n, a, b, dp1[2005][2005], dp2[2005][2005];

int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++)
    cin >> w[i].p >> w[i].c >> w[i].x;

  sort(w + 1, w + n + 1, [](const cow &l, const cow &r) { 
    return l.x < r.x; 
  });

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= b; j++) {
      if (j >= w[i].x * w[i].c)
        dp1[i][j] = max(dp1[i][j], dp1[i-1][j-w[i].x*w[i].c] + w[i].p);
      dp1[i][j] = max(dp1[i][j], dp1[i-1][j]);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= b; j++) {
      int k = b - j;
      if (w[i].c - k / w[i].x <= a && w[i].c - k / w[i].x >= 0)
        dp2[i][w[i].c-k/w[i].x] = max(dp2[i][w[i].c-k/w[i].x], dp1[i-1][j] + w[i].p);
      dp2[i][0] = max(dp2[i][0], dp1[i-1][j]);
    }
    for (int j = 0; j <= a; j++) {
      if (j >= w[i].c)
        dp2[i][j] = max(dp2[i][j], dp2[i-1][j-w[i].c] + w[i].p);
      dp2[i][j] = max(dp2[i][j], dp2[i-1][j]);
    }
  }

  cout << dp2[n][a] << '\n';
  return 0;
}

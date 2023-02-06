#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, q;
string s[1505];
int r[1505], c[1505], cnt[1505][1505];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i] >> r[i];
  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cnt[i][j]++;
      if (s[i][j] == 'R') {
        cnt[i][j+1] += cnt[i][j];
      } else {
        cnt[i+1][j] += cnt[i][j];
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cnt[i][n] * r[i];
    ans += cnt[n][i] * c[i];
  }
  cout << ans << '\n';

  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y, --x, --y;

    int pre, now;
    int i = x, j = y, t = cnt[x][y];
    while (1) {
      cnt[i][j] -= t;
      if (i == n || j == n) {
        pre = (i == n) ? c[j] : r[i];
        break;
      }
      (s[i][j] == 'D') ? i++ : j++;
    }
    s[x][y] = (s[x][y] == 'R') ? 'D' : 'R';
    i = x, j = y;
    while (1) {
      cnt[i][j] += t;
      if (i == n || j == n) {
        now = (i == n) ? c[j] : r[i];
        break;
      }
      (s[i][j] == 'D') ? i++ : j++;
    }
    ans -= cnt[x][y] * pre;
    ans += cnt[x][y] * now;

    cout << ans << '\n';
  }
  return 0;
}

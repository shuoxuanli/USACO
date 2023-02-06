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

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == n || j == n) {
        ans += cnt[i][j] * (i == n ? c[j] : r[i]);
        continue;
      }
      cnt[i][j]++;
      if (s[i][j] == 'R') {
        cnt[i][j+1] += cnt[i][j];
      } else {
        cnt[i+1][j] += cnt[i][j];
      }
    }
  }
  cout << ans << '\n';

  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y, --x, --y;

    int i = x, j = y;
    while (i != n && j != n) {
      (s[i][j] == 'D') ? i++ : j++;
      cnt[i][j] -= cnt[x][y];
      if (i == n || j == n) {
        ans -= cnt[x][y] * (i == n ? c[j] : r[i]);
      }
    }
    s[x][y] = (s[x][y] == 'R') ? 'D' : 'R';
    i = x, j = y;
    while (i != n && j != n) {
      (s[i][j] == 'D') ? i++ : j++;
      cnt[i][j] += cnt[x][y];
      if (i == n || j == n) {
        ans += cnt[x][y] * (i == n ? c[j] : r[i]);
      }
    }

    cout << ans << '\n';
  }
  return 0;
}

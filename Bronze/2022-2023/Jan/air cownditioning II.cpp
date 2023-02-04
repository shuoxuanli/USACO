#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, m, ans = INT_MAX;
int s[101], a[11], b[11], p[11], c[11];

void find(int i, int val) {
  if (i == m + 1) {
    for (int j = 0; j <= 100; j++)
      if (s[j] > 0) return;
    ans = min(ans, val);
    return;
  }

  for (int j = i + 1; j <= m + 1; j++) {
    for (int k = a[j]; k <= b[j]; k++) {
      s[k] -= p[j];
    }
    find(j, val + c[j]);
    for (int k = a[j]; k <= b[j]; k++) {
      s[k] += p[j];
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int st, ed, c;
    cin >> st >> ed >> c;
    for (int j = st; j <= ed; j++)
      s[j] += c;
  }

  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> p[i] >> c[i];
  }

  find(0, 0);
  cout << ans << '\n';
  return 0;
}

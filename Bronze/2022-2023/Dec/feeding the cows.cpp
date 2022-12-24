#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  int ans = 0;
  int g = -1, h = -1;
  string q = string(n, '.');
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G' && g < i) {
      ans++;
      g = i + 2 * k;
      int pos = min(i + k, n - 1);
      if (q[pos] != '.') pos--;
      q[pos] = 'G';
    }
    if (s[i] == 'H' && h < i) {
      ans++;
      h = i + 2 * k;
      int pos = min(i + k, n - 1);
      if (q[pos] != '.') pos--;
      q[pos] = 'H';
    }
  }

  cout << ans << '\n';
  cout << q << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

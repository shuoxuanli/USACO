#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int t;
string a, b;

void solve() {
  cin >> a >> b;

  int ans = 0;
  vector<int> to(100), deg(100);
  for (int i = 0; i < sz(a); i++) {
    int va = (a[i] >= 'a' ? (a[i] - 'a') : (a[i] - 'A' + 26)) + 1;
    int vb = (b[i] >= 'a' ? (b[i] - 'a') : (b[i] - 'A' + 26)) + 1;
    if (to[va] && to[va] != vb) {
      cout << "-1\n";
      return;
    }
    if (!to[va]) {
      deg[vb]++;
      to[va] = vb;
      ans += (a[i] != b[i]);
    }
  }

  int num = 0, sum = 0;
  vector<bool> vis(100);
  for (int i = 1; i <= 52; i++) {
    bool ok = true;
    int u = i, len = 0;
    vector<bool> v(100);
    while (!v[u]) {
      len++;
      v[u] = true;
      ok &= (deg[u] == 1);
      u = to[u];
    }
    if (u && ok && !vis[u]) {
      sum += len;
      num += (to[u] != u);
    }
    for (int j = 1; j <= 52; j++)
      vis[j] = vis[j] || v[j];
  }

  if (sum + num > 52) {
    cout << "-1\n";
    return;
  }

  cout << ans + num << '\n';
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

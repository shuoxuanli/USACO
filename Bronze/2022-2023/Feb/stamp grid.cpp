#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int t, n, k;
bool vis[21][21];
string a[21], b[21];

void rot() {
  for (int i = 0; i < k / 2; i++) {
    for (int j = i; j < k - i - 1; j++) {
      swap(b[i][j], b[k-j-1][i]);
      swap(b[k-j-1][i], b[k-i-1][k-j-1]);
      swap(b[k-i-1][k-j-1], b[j][k-1-i]);
    }
  }
}

void chk(int x, int y) {
  for (int t = 0; t < 4; t++) {
    rot();
    bool ok = true;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++)
        ok &= (a[x+i][y+j] == '*' || b[i][j] == '.');
    }
    if (!ok)
      continue;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++)
        vis[x+i][y+j] |= (b[i][j] == '*');
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> k;
  for (int i = 0; i < k; i++)
    cin >> b[i];

  memset(vis, 0, sizeof(vis));
  for (int i = 0; i <= n - k; i++) {
    for (int j = 0; j <= n - k; j++) {
      chk(i, j);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '*' && !vis[i][j]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

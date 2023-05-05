#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int t, n, m, k;
int a[101], mx[51], mn[51], cnt[51];
int adj[51][51], und[51][51], cov[51][101];

void solve() {
  cin >> n >> m;

  memset(cnt, 0, sizeof(cnt));
  memset(adj, 0, sizeof(adj));
  memset(cov, 0, sizeof(cov));
  memset(und, 0, sizeof(und));
  for (int i = 1; i <= m; i++) {
    cin >> k;
    memset(mx, -1, sizeof(mx));
    memset(mn, -1, sizeof(mn));
    for (int j = 1; j <= k; j++) {
      cin >> a[j];
      cnt[a[j]]++;
      cov[a[j]][i] = true;
      mx[a[j]] = j;
      if (mn[a[j]] == -1) mn[a[j]] = j;
    }
    for (int j = 1; j <= n; j++) {
      for (int k = mn[j] + 1; k < mx[j]; k++) {
        adj[a[k]][j]++;
      }
    }
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (mx[j] != -1 && mx[j] < mn[k]) {
          und[j][k] = true;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int prv = -1;
    for (int j = 1; j <= m; j++) {
      if (cov[i][j]) {
        if (prv + 1 == j || prv == -1) {
          prv = j;
        } else {
          cout << "NO\n";
          return;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (adj[i][j] && adj[j][i]) {
        cout << "NO\n";
        return;
      }
      if (und[i][j] && und[j][i]) {
        cout << "NO\n";
        return;
      }
      if (adj[i][j] && adj[i][j] != cnt[i]) {
        cout << "NO\n";
        return;
      }
    }
  }

  cout << "YES\n";
}

int main() {
  cin >> t;
  while (t--) solve();
  return 0;
}

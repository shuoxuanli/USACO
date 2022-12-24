#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, m;
bool va[101], vb[101];

void solve() {
  cin >> n >> m;

  memset(va, 0, sizeof(va));
  memset(vb, 0, sizeof(vb));

  vector<string> a, b;
  for (int i = 0; i < m; i++) {
    int type;
    string s;
    cin >> s >> type;
    if (type == 0) {
      a.push_back(s);
    } else {
      b.push_back(s);
    }
  }

  auto testa = [&](int j) {
    bool one = true, zero = true;
    for (int k = 0; k < sz(a); k++) {
      if (va[k]) continue;
      one &= a[k][j] == '1';
      zero &= a[k][j] == '0';
    }
    for (int k = 0; k < sz(b); k++) {
      if (b[k][j] == '0' && one) vb[k] = true;
      if (b[k][j] == '1' && zero) vb[k] = true;
    }
  };

  auto testb = [&](int j) {
    bool one = true, zero = true;
    for (int k = 0; k < sz(b); k++) {
      if (vb[k]) continue;
      one &= b[k][j] == '1';
      zero &= b[k][j] == '0';
    }
    for (int k = 0; k < sz(a); k++) {
      if (a[k][j] == '0' && one) va[k] = true;
      if (a[k][j] == '1' && zero) va[k] = true;
    }
  };

  for (int i = 0; i < 2 * m; i++) {
    for (int j = 0; j < n; j++) {
      testa(j);
      testb(j);
    }
  }

  for (int i = 0; i < sz(a); i++) {
    if (!va[i]) {
      cout << "LIE\n";
      return;
    }
  }
  for (int i = 0; i < sz(b); i++) {
    if (!vb[i]) {
      cout << "LIE\n";
      return;
    }
  }

  cout << "OK\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

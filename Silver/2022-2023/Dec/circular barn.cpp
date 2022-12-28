#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int t, n;
int p[5000005], cnt[5000005], mx[4];

void solve() {
  cin >> n;

  int li = -1, ri = -1;
  int l = 1E9, r = 1E9;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    if (a % 4 == 0) {
      if (cnt[a] < l) l = cnt[a], li = i;
    } else {
      if (cnt[a] < r) r = cnt[a], ri = i;
    }
  }

  l++;
  if (l < r || (l == r && li < ri)) {
    cout << "Farmer Nhoj\n";
  } else {
    cout << "Farmer John\n";
  }
}

int main() {
  for (int i = 2; i <= 5E6; i++) if (!p[i]) {
    for (int j = i + i; j <= 5E6; j += i) {
      p[j] = 1;
    }
  }

  for (int i = 1; i <= 5E6; i++) {
    if (!p[i]) {
      cnt[i] = 1;
      mx[i % 4] = i;
    } else {
      cnt[i] = (i % 4 == 0) ? i / 4 : cnt[i - mx[i % 4]] + 1;
    }
  }

  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

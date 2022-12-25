#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, q, a[2005];
set<int> h[2005];

bool cmp(int i, int j, int k) {
  ll y1 = a[j] - a[i];
  ll y2 = a[k] - a[i];
  ll x1 = abs(j - i);
  ll x2 = abs(k - i);
  return y1 * x2 >= y2 * x1;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int lst = -1;
    for (int j = i + 1; j < n; j++) {
      if (j == i + 1 || cmp(i, j, lst)) {
        ans++;
        lst = j;
        h[i].insert(j);
      }
    }
  }

  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y, x--;
    a[x] += y;

    for (int i = 0; i < x; i++) {
      auto it = h[i].upper_bound(x);
      if (cmp(i, x, *(--it)) && !h[i].count(x)) {
        ans++;
        h[i].insert(x);
      }
      vector<int> e;
      it = h[i].upper_bound(x);
      while (it != h[i].end() && !cmp(i, *it, x)) {
        e.push_back(*it);
        it++, ans--;
      }
      for (auto j : e) h[i].erase(j);
    }

    ans -= sz(h[x]);
    h[x].clear();

    int lst = -1;
    for (int i = x + 1; i < n; i++) {
      if (i == x + 1 || cmp(x, i, lst)) {
        ans++;
        lst = i;
        h[x].insert(i);
      }
    }

    cout << ans << '\n';
  }
  return 0;
}

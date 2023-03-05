#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, m;
int l[100001], r[100001];

struct cow {
  ll x, y, t;
} a[100001], b[100001];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i].x >> a[i].y >> a[i].t;
  for (int i = 0; i < m; i++)
    cin >> b[i].x >> b[i].y >> b[i].t;

  auto cmp = [&](const cow &a, const cow &b) { 
    return a.t < b.t; 
  };
  sort(a, a + n, cmp);
  sort(b, b + m, cmp);

  auto reach = [&](const cow &a, const cow &b) {
    ll dx = abs(a.x - b.x);
    ll dy = abs(a.y - b.y);
    ll dt = abs(a.t - b.t);
    return dx * dx + dy * dy <= dt * dt;
  };

  memset(l, -1, sizeof(l));
  for (int i = 0, j = 0; i < m; i++) {
    while (j < n && a[j].t < b[i].t)
      j++;
    if (a[j-1].t < b[i].t) l[i] = j - 1;
  }
  memset(r, -1, sizeof(r));
  for (int i = m - 1, j = n - 1; i >= 0; i--) {
    while (j >= 0 && a[j].t >= b[i].t)
      j--;
    if (a[j+1].t >= b[i].t) r[i] = j + 1;
  }

  int ans = m;
  for (int i = 0; i < m; i++) {
    bool ok = true;
    if (l[i] != -1) ok &= reach(a[l[i]], b[i]);
    if (r[i] != -1) ok &= reach(a[r[i]], b[i]);
    ans -= ok;
  }

  cout << ans << '\n';
  return 0;
}

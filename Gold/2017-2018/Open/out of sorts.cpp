#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

template <class T> struct bit {
  const int n;
  vector<T> c;
  bit(int n) : n(n), c(n + 1) {}
  void upd(int i, T v) {
    for (; i <= n; i += i & -i) c[i] += v;
  }
  T qry(int i) {
    T res = 0;
    for (; i > 0; i -= i & -i) res += c[i];
    return res;
  }
  T qry(int l, int r) { return qry(r) - qry(l - 1); }
};

int n;
pair<int, int> a[100001];

int main() {
  ifstream cin("sort.in");
  ofstream cout("sort.out");

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n);

  int ans = 1;
  bit<int> f(n);
  for (int i = 1; i < n; i++) {
    f.upd(a[i].second, 1);
    ans = max(ans, i - f.qry(i));
  }

  cout << ans << '\n';
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n, m, k, l[105], r[105];

vector<int> init() {
  vector<int> a(n + 1, 0);
  iota(a.begin(), a.end(), 0);
  for (int i = 0; i < m; ++i) {
    for (int x = l[i], y = r[i]; x < y; ++x, --y) {
      swap(a[x], a[y]);
    }
  }
  return a;
}

vector<int> trans(vector<int> a, vector<int> rule) {
  vector<int> ans(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    ans[i] = a[rule[i]];
  }
  return ans;
}

int main() {
  freopen("swap.in", "r", stdin);
  freopen("swap.out", "w", stdout);
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i];
  }
  vector<int> a;
  for (int i = 0; i <= n; ++i) {
    a.push_back(i);
  }
  vector<int> base = init();
  while (k) {
    if (k & 1) {
      a = trans(a, base);
    }
    base = trans(base, base);
    k >>= 1;
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << endl;
  }
  return 0;
}

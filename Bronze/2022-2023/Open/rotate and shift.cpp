#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, k, t, a[200001], ans[200001];

int main() {
  cin >> n >> k >> t;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  a[k] = n;

  for (int i = 0, j = 0; i < n; i++) {
    if (a[j + 1] == i) j++;
    ll gap = a[j + 1] - a[j];
    int pos = (i + gap + gap * ((t - 1 - i + a[j]) / gap)) % n;
    ans[pos] = i;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}

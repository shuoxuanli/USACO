#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, a[100001];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int sum = accumulate(a, a + n, 0);
  for (int i = 0, p = 0; i < sum; i++) {
    if (p == 0) {
      cout << 'R';
      a[p++]--;
    } else if (a[p] > a[p - 1]) {
      cout << 'R';
      a[p++]--;
    } else {
      cout << 'L';
      a[--p]--;
    }
  }
  return 0;
}

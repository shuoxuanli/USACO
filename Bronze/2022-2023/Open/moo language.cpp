#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n;
string s;

int main() {
  cin >> n >> s;

  int mn = 0, mx = 0, con = 0;
  for (int i = 0; i < n; i++) if (s[i] == 'F') {
    int j = i - 1;
    while (i < n && s[i] == 'F') i++;

    if (j == -1 || i == n) {
      con += i - j - 1 - (j == -1 && i == n);
    } else if (s[i] == s[j]) {
      mn += (i - j) & 1;
      mx += i - j;
    } else {
      mn += (i - j - 1) & 1;
      mx += i - j - 1;
    }
  }

  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1] && s[i] != 'F') {
      mx++, mn++;
    }
  }

  if (con) {
    cout << mx + con - mn + 1 << '\n';
    for (int i = mn; i <= mx + con; i++) {
      cout << i << '\n';
    }
  } else {
    cout << (mx - mn) / 2 + 1 << '\n';
    for (int i = mn; i <= mx; i += 2) {
      cout << i << '\n';
    }
  }
  return 0;
}

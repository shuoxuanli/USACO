#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int q;
string s;

int main() {
  cin >> q;
  while (q--) {
    cin >> s;

    int ans = INT_MAX;
    for (int i = 1; i < sz(s) - 1; i++) if (s[i] == 'O') {
      ans = min(ans, sz(s) - 3 + (s[i-1] != 'M') + (s[i+1] != 'O'));
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';
  }
  return 0;
}

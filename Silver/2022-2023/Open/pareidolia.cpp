#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

string s;
ll cnt[7];

int main() {
  cin >> s;

  ll ans = 0;
  string tar = "bessie";
  for (int i = 0; i < sz(s); i++) {
    cnt[0]++;
    for (int j = 5; j >= 0; j--) {
      if (s[i] == tar[j]) {
        cnt[j + 1] += cnt[j];
        cnt[j] = 0;
      }
    }
    ans += cnt[6] * (sz(s) - i);
    cnt[0] += cnt[6];
    cnt[6] = 0;
  }

  cout << ans << '\n';
  return 0;
}

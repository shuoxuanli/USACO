#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int t, n, c, p;

void solve() {
  cin >> n >> c >> p;

  vector<string> nn, iv, tv, con;
  for (int i = 0; i < n; i++) {
    string w, tp;
    cin >> w >> tp;
    if (tp[0] == 'n') {
      nn.push_back(w);
    } else if (tp[0] == 'i') {
      iv.push_back(w);
    } else if (tp[0] == 't') {
      tv.push_back(w);
    } else {
      con.push_back(w);
    }
  }

  int len = 0, mxi = 0, mxj = 0;
  for (int i = 0; i <= sz(iv); i++) {
    for (int j = 0; j <= sz(tv); j++) {
      int noun = i + 2 * j;
      int conj = min(sz(con), (i + j) / 2);
      int sent = i + j - conj;
      if (sz(nn) >= noun && p >= sent) {
        if (j) noun += min(sz(nn) - noun, c);
        if (noun + conj + i + j > len) {
          len = noun + conj + i + j;
          mxi = i;
          mxj = j;
        }
      }
    }
  }

  string ans = "";
  int cnt = 0, add = 1;
  int ptr = min(sz(con), (mxi + mxj) / 2);
  for (int i = 0; i < mxi; i++, add ^= 1) {
    ans += nn[cnt++] + " " + iv[i];
    if (ptr && add) {
      ans += " " + con[--ptr];
    } else {
      ans += ".";
    }
    ans += " ";
  }
  for (int i = 0; i < mxj; i++, add ^= 1) {
    ans += nn[cnt++] + " " + tv[i] + " " + nn[cnt++];
    if (ptr && add) {
      ans += " " + con[--ptr];
    } else {
      ans += ".";
    }
    ans += " ";
  }
  if (ans.back() == ' ') ans.pop_back();

  if (mxj) {
    ans.pop_back();
    for (int i = 0; i < min(sz(nn) - mxi - 2 * mxj, c); i++)
      ans += ", " + nn[cnt++];
    ans += ".";
  }

  cout << len << '\n' << ans << '\n';
}

int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}

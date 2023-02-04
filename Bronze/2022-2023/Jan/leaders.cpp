#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, a[100001];
string s;

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> a[i], a[i]--;

  int gl = n, gr = 0;
  int hl = n, hr = 0;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == 'G') {
      gl = min(gl, i);
      gr = max(gr, i);
    } else {
      hl = min(hl, i);
      hr = max(hr, i);
    }
  }
  if (a[gl] < gr) gl = -1;
  if (a[hl] < hr) hl = -1;

  int ans = (gl != -1) + (hl != -1);
  for (int i = 0; i < sz(s); i++) {
    if (i == gl || i == hl)
      continue;
    if (s[i] == 'G' && i < hl && a[i] >= hl)
      ans++;
    if (s[i] == 'H' && i < gl && a[i] >= gl)
      ans++;
  }

  cout << ans - 1 << '\n';
}

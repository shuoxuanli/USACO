#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

string s;
int q, pc[200001], po[200001], pw[200001];

int main() {
  cin >> s;

  for (int i = 0; i < sz(s); i++) {
    pc[i+1] = pc[i] + (s[i] == 'C');
    po[i+1] = po[i] + (s[i] == 'O');
    pw[i+1] = pw[i] + (s[i] == 'W');
  }

  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;

    int c = pc[r] - pc[l-1];
    int o = po[r] - po[l-1];
    int w = pw[r] - pw[l-1];

    if (c % 2 == 0 && o % 2 == 1 && w % 2 == 1) {
      cout << 'Y';
    } else if (c % 2 == 1 && o % 2 == 0 && w % 2 == 0) {
      cout << 'Y';
    } else {
      cout << 'N';
    }
  }
  return 0;
}

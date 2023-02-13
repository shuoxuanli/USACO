#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int MOD = 1E9 + 7;
int n;
ll sx[100005], sy[100005];

struct pt {
  int x, y;
} a[100005];

int main() {
  ifstream cin("triangles.in");
  ofstream cout("triangles.out");

  cin >> n;

  map<pair<int, int>, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    mp[{a[i].x, a[i].y}] = i;
  }

  sort(a + 1, a + 1 + n, [](const pt &l, const pt &r) {
    return l.x < r.x || (l.x == r.x && l.y < r.y);
  });
  for (int i = 1; i <= n; i++) {
    int j = i;
    ll sum = 0;
    while (a[i].x == a[j].x) {
      sum += a[j].y - a[i].y;
      j++;
    }
    j--;
    for (int k = i; k <= j; k++) {
      sum += (k - i) * (a[k].y - a[k - 1].y);
      sx[mp[{a[k].x, a[k].y}]] = sum;
      sum -= (j - k) * (a[k + 1].y - a[k].y);
    }
    i = j;
  }

  sort(a + 1, a + 1 + n, [](const pt &l, const pt &r) {
    return l.y < r.y || (l.y == r.y && l.x < r.x);
  });
  for (int i = 1; i <= n; i++) {
    int j = i;
    ll sum = 0;
    while (a[i].y == a[j].y) {
      sum += a[j].x - a[i].x;
      j++;
    }
    j--;
    for (int k = i; k <= j; k++) {
      sum += (k - i) * (a[k].x - a[k - 1].x);
      sy[mp[{a[k].x, a[k].y}]] = sum;
      sum -= (j - k) * (a[k + 1].x - a[k].x);
    }
    i = j;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + 1LL * sx[i] * sy[i] % MOD) % MOD;
  }

  cout << ans << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, f[200001];

struct edge {
  int x, y, w;
} a[100001];

int find(int x) { 
  return f[x] == x ? x : f[x] = find(f[x]); 
}

bool join(int x, int y) {
  if ((x = find(x)) == (y = find(y)))
    return false;
  f[x] = y;
  return true;
}

int main() {
  cin >> n;

  iota(f + 1, f + 1 + 2 * n, 1);
  for (int i = 1; i <= n; i++) {
    int c, v1, v2, v3, v4;
    cin >> c >> v1 >> v2 >> v3 >> v4;
    join(v1, v2);
    join(v3, v4);
    a[i] = {v1, v3, c};
  }

  sort(a + 1, a + 1 + n, [](const edge &u, const edge &v) { 
    return u.w < v.w; 
  });

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (join(a[i].x, a[i].y))
      ans += a[i].w;
  }

  cout << ans << '\n';
  return 0;
}

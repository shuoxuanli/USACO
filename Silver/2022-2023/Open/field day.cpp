#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

string s;
int n, c, a[100001], dis[300001];

int main() {
  cin >> c >> n;

  memset(dis, 0x3f, sizeof(dis));
  for (int i = 0; i < n; i++) {
    cin >> s;
    int x = 0;
    for (int j = 0; j < c; j++) {
      if (s[j] == 'H') x |= (1 << j);
    }
    a[i] = x;
    dis[x] = 0;
  }

  for (int j = 0; j < c; j++) {
    for (int i = 0; i < (1 << c); i++) {
      dis[i ^ (1 << j)] = min(dis[i ^ (1 << j)], dis[i] + 1);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << c - dis[a[i] ^ ((1 << c) - 1)] << '\n';
  }
  return 0;
}

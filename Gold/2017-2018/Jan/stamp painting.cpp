#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int MOD = 1E9 + 7;
int n, m, k;
ll s[1000001];

int main() {
  ifstream cin("spainting.in");
  ofstream cout("spainting.out");

  cin >> n >> m >> k;

  s[0] = 0;
  for (int i = 1; i < k; i++) {
    s[i] = (m * s[i - 1] % MOD + m) % MOD;
  }
  for (int i = k; i <= n; i++) {
    s[i] = (m * s[i - 1] % MOD - (m - 1) * s[i - k] % MOD) % MOD;
  }

  ll ans = 1;
  for (int i = 1; i <= n; i++)
    ans = ans * m % MOD;

  cout << (ans - (s[n] - s[n - 1] + MOD) % MOD + MOD) % MOD;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("breedflip.in", "r", stdin);
  freopen("breedflip.out", "w", stdout);

  int n;
  cin >> n;

  string a, b;
  cin >> a;
  cin >> b;

  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] != b[i] && (i == n - 1 || a[i + 1] == b[i + 1]))
      ans++;
  }
  cout << ans << endl;
  return 0;
}

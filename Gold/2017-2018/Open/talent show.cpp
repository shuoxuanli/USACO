#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define NMAX 250
#define WMAX 1000

int n, w, talent[NMAX], weights[NMAX];
ll dp[WMAX + 1];

bool check(int y) {
  fill(dp, dp+w+1, -LLONG_MAX);
  dp[0] = 0;

  for (int j = 0; j < n; j++) {
    ll value = 1000*(ll)talent[j] - y*(ll)weights[j];
    int inc = weights[j];
    for (int k = w; k >= 0; k--) {
      int k1 = min(w, k + inc);
      if (dp[k] != -LLONG_MAX) {
        dp[k1] = max(dp[k1], dp[k] + value);
      }
    }
  }
  return dp[w] >= 0;
}

int main() {
  ifstream cin("talent.in");
  ofstream cout("talent.out");
  
  cin>>n>>w;

  for (int i = 0; i < n; i++) {
    cin>>weights[i]>>talent[i];
  }

  int l = 0, r = WMAX*WMAX*NMAX, ans = 0;
  while (l <= r) {
    int mid = (l+r) / 2;
    if (check(mid)) {
      l = mid+1;
      ans = mid;
    } else {
      r = mid-1;
    }
  }
  
  cout<<ans<<endl;
  return 0;
}

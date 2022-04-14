#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 1;
char hps[maxN];
int h[maxN], p[maxN], s[maxN];

int main() {
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 1; i  <= n; i++) {
    cin>>hps[i];
  }

  for(int i = 1; i <= n; i++) {
    h[i] = h[i-1];
    p[i] = p[i-1];
    s[i] = s[i-1];

    if(hps[i] == 'P') {
      s[i]++;
    }
    else if(hps[i] == 'H') {
      p[i]++;
    } else {
      h[i]++;
    }
  }

  int ans = INT_MIN;
  for(int i = 1; i <= n; i++) {
    int before = h[i];
    int after = p[n] - p[i];
    ans = max(ans, before + after);
  }

  for(int i = 1; i <= n; i++) {
    int before = p[i];
    int after = s[n] - s[i];
    ans = max(ans, before + after);
  }

  for(int i = 1; i <= n; i++) {
    int before = s[i];
    int after = h[n] - h[i];
    ans = max(ans, before + after);
  }

  for(int i = 1; i <= n; i++) {
    int before = p[i];
    int after = h[n] - h[i];
    ans = max(ans, before + after);
  }

  for(int i = 1; i <= n; i++) {
    int before = s[i];
    int after = p[n] - p[i];
    ans = max(ans, before + after);
  }

  for(int i = 1; i <= n; i++) {
    int before = h[i];
    int after = s[n] - s[i];
    ans = max(ans, before + after);
  }

  cout<<ans<<endl;
  return 0;
}

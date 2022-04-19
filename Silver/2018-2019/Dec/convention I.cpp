#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
int n, m, c;
int t[maxN];

bool check(int wait) {
  int bus = 1;
  int pre = t[0];
  int preI = 0;
  for(int i=1;i< n;i++) {
    if(t[i] - pre > wait || i + 1 - preI > c) {
      bus++;
      pre = t[i];
      preI = i;
    }
  }
  return bus <= m;
}

int main() {
  freopen("convention.in", "r", stdin);
  freopen("convention.out", "w", stdout);

  cin>>n>>m>>c;

  for(int i = 0; i < n; i++) {
    cin>>t[i];
  }

  sort(t, t+n);

  int ans = 0;
  int l = 0, r = t[n-1];
  while(l <= r) {
    int mid = (l+r)/2;
    if(check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout<<ans<<endl;
  return 0;
} 

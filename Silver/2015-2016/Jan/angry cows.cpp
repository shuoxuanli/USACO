#include <bits/stdc++.h>
using namespace std;

int n, k;
int haybales[50001];

bool check(int rad) {
  int cow = 0;
  int last = 0;
  while(last <= n-1) {
    int tmp = last;
    while(tmp <= n-1 && haybales[tmp] <= haybales[last] + rad*2) {
      tmp++;
    }
    last = tmp;
    cow++;
  }

  return cow <= k;
}

int main() {
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  cin>>n>>k;

  for(int i = 0; i < n; i++) {
    cin>>haybales[i];
  }

  sort(haybales, haybales + n);

  int l = 1, r = (haybales[0] + haybales[n-1])/2;
  int ans = 0;
  while(l <= r) {
    int mid = (l+r)/2;
    if(check(mid)) {
      r = mid-1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }

  cout<<ans<<endl;
  return 0;
}

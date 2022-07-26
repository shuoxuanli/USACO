#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, k, l, a[100001];

bool chk(int m) {
  ll need = 0;
  for(int i = 0; i < m; i++) {
    need += max(0, m-a[i]);
  }
  return need <= (ll)k*(ll)l && m-a[m-1] <= k;
}

int main() {
  cin>>n>>k>>l;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  
  sort(a, a+n, greater<int>());
  
  int lo = 0, hi = n, ans;
  while(lo <= hi) {
    int m = (lo+hi)>>1;
    if(chk(m)) {
      lo = m+1;
      ans = m;
    } else {
      hi = m-1;
    }
  }
  
  cout<<ans<<endl;
  return 0;
}

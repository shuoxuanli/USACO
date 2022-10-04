#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n;
int a[50005];

int main() {
  ifstream cin("angry.in");
  ofstream cout("angry.out");
  
  cin>>n;
  for(int i = 0; i < n; i++) {
    cin>>a[i];
    a[i] *= 2;
  }
  sort(a, a+n);
  
  auto chk1 = [&](int st, int r) -> bool {
    int i = n-1;
    while(st > a[0]) {
      while(i > 0 && a[i-1] >= st - r)
        i--;
      if(a[i] >= st) {
        return false;
      }
      st = a[i], r -= 2;
    }
    return true;
  };
  
  auto chk2 = [&](int st, int r) -> bool {
    int i = 0;
    while(st < a[n-1]) {
      while(i < n-1 && a[i+1] <= st + r)
        i++;
      if(a[i] <= st) {
        return false;
      }
      st = a[i], r -= 2;
    }
    return true;
  };
  
  int l = 0, r = a[n-1];
  while(l < r) {
    int m = l + (r-l)/2;
    int lo = a[0], hi = a[n-1];
    while(lo < hi) {
      int mid = lo + (hi-lo)/2;
      if(chk2(mid, m))
        hi = mid;
      else
        lo = mid+1;
    }
    if(chk1(lo, m))
      r = m;
    else
      l = m+1;
  }
  
  cout<<(l/2)<<'.'<<(l%2 == 1 ? '5' : '0')<<endl;
  return 0;
}

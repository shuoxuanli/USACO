#include<bits/stdc++.h>
using namespace std;
 
int n, k;
int a[100000];
int mod;
 
bool cmp(int a,int b) {
  return (a%mod) > (b%mod);
}
 
int main() {
  ifstream cin("berries.in");
  ofstream cout("berries.out");
  
  cin >> n >> k;
  int m = 0;
  for(int i=0;i<n;i++) {
    cin >> a[i];
    m = max(m, a[i]);
  }
  
  int best = 0;
  for(int b=1;b <= m; b++) {
    int full = 0;
    for(int i=0;i<n;i++)
      full += a[i]/b;
    if(full < k/2)
      break;
    if(full >= k) {
      best = max(best, b*(k/2));
      continue;
    }
    mod = b;
    sort(a, a+n, cmp);
    int cur = b*(full - k/2);
    for(int i=0;i<n && i+full<k;i++)
      cur += a[i]%b;
    best = max(best,cur);
  }
  cout << best << '\n';
}

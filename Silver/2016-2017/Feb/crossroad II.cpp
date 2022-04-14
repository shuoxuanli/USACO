#include <bits/stdc++.h>
using namespace std;

int signals[100001], prefix[100001];

int main() {
  freopen("maxcross.in", "r", stdin);
  freopen("maxcross.out", "w", stdout);

  int n, b, k;
  cin>>n>>k>>b;

  for(int i = 1; i <= b; i++) {
    int broken;
    cin>>broken;
    signals[broken] = 1;
  }

  for(int i = 1; i <= n; i++) {
    prefix[i] = prefix[i-1] + signals[i];
  }

  int ans = INT_MAX;
  for(int i = 1; i <= n-k+1; i++) {
    ans = min(prefix[i+k-1] - prefix[i-1], ans);
  }

  cout<<ans<<endl;
  return 0;
} 

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
int diamonds[maxN], prefix[maxN], val[maxN];

int main() {
  int n, k;
  
  ofstream cout("diamond.out");
  ifstream cin("diamond.in");

  cin>>n>>k;

  for(int i = 0; i < n; i++) {
    cin>>diamonds[i];
  }

  sort(diamonds, diamonds+n);

  int l = 0, r = 0;
  while(l < n) {
    while(diamonds[r] - diamonds[l] <= k && r < n) {
      r++;
    }
    prefix[l] = r-l;
    l++;
  }

  for(int i = n-1; i>= 0; i--) {
    val[i] = max(prefix[i], val[i+1]);
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans = max(ans, prefix[i] + val[i+prefix[i]]);
  }

  cout<<ans<<endl;
  return 0;
}

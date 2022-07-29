#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 1e5+1;
ll n, m, f[maxN], s[maxN];

int main() {
  ifstream cin("hayfeast.in");
  ofstream cout("hayfeast.out");
  
  cin>>n>>m;

  for(int i = 0; i < n; i++) {
    cin>>f[i]>>s[i];
  }
  
  ll sum = 0, ans = INT_MAX;
  multiset<ll> cur;
  for(int i = 0, j = 0; i < n; i++) {
    while(sum < m && j < n) {
      sum += f[j];
      cur.insert(s[j]);
      j++;
    }
    if(sum < m) break;
    ans = min(ans, *cur.rbegin());
    cur.erase(cur.find(s[i]));
    sum -= f[i];
  }
  
  cout<<ans<<endl;
  return 0;
} 

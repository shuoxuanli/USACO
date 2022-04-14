#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("pairup.in", "r", stdin);
  freopen("pairup.out", "w", stdout);
  
  int n;
  cin>>n;

  vector<pair<int, int>> v;

  for(int i = 0; i < n; i++) {
    int x, y;
    cin>>x>>y;
    v.push_back(make_pair(y,x));
  } 
  
  sort(v.begin(), v.end());

  int l = 0, r = n-1, t = 0;
  while(l <= r) {
    t = max(v[l].first + v[r].first, t);
    while(v[l].second > 0 && v[r].second > 0) {
      v[l].second--;
      v[r].second--;
    }
    if(v[l].second == 0) {
      l++;
    } 
    if(v[r].second == 0) {
      r--;
    }
  }

  cout<<t<<endl;
  return 0;
} 

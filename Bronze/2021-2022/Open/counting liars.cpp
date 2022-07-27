#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())

int main() {
  int n;
  cin>>n;
  
  vector<int> l, g;
  for(int i = 0; i < n; i++) {
    char c; int p;
    cin>>c>>p;
    if(c == 'L') l.push_back(p);
    else g.push_back(p);
  }
  
  sort(l.begin(), l.end());
  sort(g.begin(), g.end());
  
  int ans = INT_MAX;
  for(int i = 0; i < sz(l); i++) {
    bool b = 0;
    for(int j = 0; j < sz(g); j++) {
      if(l[i] >= g[j]) continue;
      ans = min(ans, i+sz(g)-j);
      b = 1;
      break;
    }
    if(!b) ans = min(ans, i);
  }
  
  cout<<ans<<endl;
  return 0;
}

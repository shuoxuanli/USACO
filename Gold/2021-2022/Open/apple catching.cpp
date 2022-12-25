#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+5;

struct apple {
  int q, t, x, m;
} a[maxN];

int n;
map<int, int> mp;

bool cmp(const apple &a, const apple &b) {
  if(a.x - a.t != b.x - b.t) {
    return a.x - a.t < b.x - b.t;
  }
  return a.q > b.q;
}

int main() {
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>a[i].q>>a[i].t>>a[i].x>>a[i].m;
  }
  
  sort(a, a+n, cmp);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(a[i].q == 2) {
      mp[a[i].x + a[i].t] += a[i].m;
    } else {
      int app = a[i].m;
      while(app) {
        map<int, int> :: iterator it;
        it = mp.lower_bound(a[i].x + a[i].t);
        if(it == mp.end()) break;
        
        int tmp = min(app, it -> second);
        if(app < it -> second) {
          it -> second -= app;
        } else {
          mp.erase(it);
        }
        
        app -= tmp;
        ans += tmp;
      }
    }
  }
  
  cout<<ans<<endl;
  return 0;
} 

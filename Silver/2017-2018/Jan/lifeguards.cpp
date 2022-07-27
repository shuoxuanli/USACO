#include <bits/stdc++.h>
using namespace std;

struct lifeguards{
  int x, y;
};

bool cmp(const lifeguards& a, const lifeguards& b) { 
  return a.x < b.x;
}

int main() {
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);

  int n;
  cin>>n;

  vector<lifeguards> wk(n);

  for(int i = 0; i < n; i++) {
    cin>>wk[i].x>>wk[i].y;
  }

  sort(wk.begin(), wk.end(), cmp);

  int tot = 0, l = 0, r = 0;

  for(int i = 0; i < n; i++) {
    if(wk[i].y > r) {
      l = max(r, wk[i].x);
      tot += wk[i].y - l;
      r = wk[i].y;
    }
  }

  int res = tot;
  lifeguards last;
  last.x = wk[n-1].y;
  wk.push_back(last);
  r = 0;
  for(int i = 0; i < n; i++) {
    int cur = min(wk[i + 1].x, wk[i].y) - max(wk[i].x, r);
    res = min(res, cur);
    r = max(r, wk[i].y);
  }

  res = max(res, 0); 
  cout << tot - res << '\n';
  return 0;
} 

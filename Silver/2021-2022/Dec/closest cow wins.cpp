#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 2e5+1;

struct grass{
  ll p, t;
} a[maxN];

ll k, m, n, p[maxN], d[maxN];

bool cmp(const grass& a, const grass& b) {
  return a.p < b.p;
}

bool cmp2(const grass& a, const grass& b) {
  return a.t > b.t;
}

int main() {
  cin>>k>>m>>n;

  for(int i = 1; i <= k; i++) {
    cin>>a[i].p>>a[i].t;
  }

  for(int i = 1; i <= m; i++) {
    cin>>p[i];
  }

  sort(a+1, a+1+k, cmp);
  sort(p+1, p+1+m);

  memset(d, 0x7f, sizeof(d));
  
  for(int i = 1; i <= k; i++) {
    int j = lower_bound(p+1, p+1+m, a[i].p)-p;
    if(j != 1) d[i] = min(d[i], a[i].p-p[j-1]);
    if(j != m+1) d[i] = min(d[i], p[j] - a[i].p);
  }

  vector<grass> ans;
  ans.push_back({a[1].p+d[1]-1,a[1].t});
  for(int i = 2; i <= k; i++) {
    if(a[i].p - d[i] < ans.back().p) {
      grass tmp = ans.back();
      ans.pop_back();
      ans.push_back({tmp.p, tmp.t + a[i].t});
    } else {
      ans.push_back({a[i].p+d[i]-1, a[i].t});
    }
  }

  sort(ans.begin(), ans.end(), cmp2);

  ll ret = 0;
  for(int i = 0; i < n; i++) {
    ret += ans[i].t;
  }

  cout<<ret<<endl;
} 

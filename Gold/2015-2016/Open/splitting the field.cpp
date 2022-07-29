#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 5e4+1;

struct pt {
  ll x, y;
} a[maxN];

struct fence {
  ll l, b, r, t;
};

int n, m;
vector<fence> hf, hl, rf, rl;
ll ans, d = LONG_MAX;

bool cmpx(pt a, pt b) {
  return a.x < b.x;
}

bool cmpy(pt a, pt b) {
  return a.y < b.y;
}

void init() {
  sort(a, a+n, cmpx);

  hf.push_back({LONG_MAX,LONG_MAX,0,0});
  for(int i = 0; i < n; i++) {
    ll l = hf.back().l, b = hf.back().b;
    ll r = hf.back().r, t = hf.back().t;
    while(i < n){
      l = min(l, a[i].x);
      r = max(r, a[i].x);
      b = min(b, a[i].y);
      t = max(t, a[i].y);
      if(i < n-1 && a[i].x == a[i+1].x) i++;
      else break;
    };
    hf.push_back({l,b,r,t});
  }

  hl.push_back({LONG_MAX,LONG_MAX,0,0});
  for(int i = n-1; i >= 0; i--) {
    ll l = hl.back().l, b = hl.back().b;
    ll r = hl.back().r, t = hl.back().t;
    while(i >= 0) {
      l = min(l, a[i].x);
      r = max(r, a[i].x);
      b = min(b, a[i].y);
      t = max(t, a[i].y);
      if(i > 0 && a[i].x == a[i-1].x) i--;
      else break;
    }
    hl.push_back({l,b,r,t});
  }

  sort(a, a+n, cmpy);
  
  rf.push_back({LONG_MAX,LONG_MAX,0,0});
  for(int i = 0; i < n; i++) {
    ll l = rf.back().l, b = rf.back().b;
    ll r = rf.back().r, t = rf.back().t;
    while(i < n) {
      l = min(l, a[i].x);
      r = max(r, a[i].x);
      b = min(b, a[i].y);
      t = max(t, a[i].y);
      if(i < n-1 && a[i].y == a[i+1].y) i++;
      else break;
    }
    rf.push_back({l,b,r,t});
  }

  rl.push_back({LONG_MAX,LONG_MAX,0,0});
  for(int i = n-1; i >= 0; i--) {
    ll l = rl.back().l, b = rl.back().b;
    ll r = rl.back().r, t = rl.back().t;
    while(i >= 0) {
      l = min(l, a[i].x);
      r = max(r, a[i].x);
      b = min(b, a[i].y);
      t = max(t, a[i].y);
      if(i > 0 && a[i].y == a[i-1].y) i--;
      else break;
    }
    rl.push_back({l,b,r,t});
  }
}

int main() {
  ifstream cin("split.in");
  ofstream cout("split.out");
  
  cin>>n;
  
  for(int i = 0; i < n; i++) {
    cin>>a[i].x>>a[i].y;
  }

  init();

  m = hf.size();
  ans = (hf[m-1].r-hf[m-1].l)*(hf[m-1].t - hf[m-1].b);
  
  for(int i = 1; i < m-1; i++) {
    ll f = (hf[i].r-hf[i].l)*(hf[i].t-hf[i].b);
    ll s = (hl[m-i-1].r-hl[m-i-1].l)*(hl[m-i-1].t-hl[m-i-1].b);
    d = min(d, f+s);
  }

  m = rf.size();
  for(int i = 1; i < m-1; i++) {
    ll f = (rf[i].r-rf[i].l)*(rf[i].t-rf[i].b);
    ll s = (rl[m-i-1].r-rl[m-i-1].l)*(rl[m-i-1].t-rl[m-i-1].b);
    d = min(d, f+s);
  }

  ans -= d;
  
  cout<<ans<<endl;
  return 0;
} 

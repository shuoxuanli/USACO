#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct cow {
  int h, idx;
} a[100001];

int n, c[100001];

bool cmp(cow a, cow b) {
  return a.h > b.h;
}

int lowbit(int x) {
  return x&(-x);
}

void upd(int x, int v) {
  for(int i = x; i <= n; i+=lowbit(i)) {
    c[i] += v;
  }
}

int qry(int x) {
  ll ans = 0;
  for(int i = x; i > 0; i-=lowbit(i)) {
    ans += c[i];
  }
  return ans;
}

int main() {
  ifstream cin("bphoto.in");
  ofstream cout("bphoto.out");
  
  cin>>n;

  for(int i = 1; i <= n; i++) {
    cin>>a[i].h;
    a[i].idx = i;
  }

  sort(a+1, a+1+n, cmp);
  
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int l = qry(a[i].idx);
    int r = i - 1 - l;
    ans += (max(l, r) > min(l,r)*2);
    upd(a[i].idx, 1);
  }

  cout<<ans<<endl;
  return 0;
} 

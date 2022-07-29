#include <bits/stdc++.h>
using namespace std;

struct pt {
  int x, y;
} a[1001];

int n, f[1001];

int find(int u) {
  return f[u]==u ? u : f[u] = find(f[u]);
}

void join(int u, int v) {
  u = find(u);
  v = find(v);
  if(u == v) return;
  f[u] = v;
}

bool dis(pt a, pt b, double d) {
  double p = sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
  return d >= p;
}

bool check(double d) {
  d = sqrt(d);
  iota(f+1, f+1+n, 1);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i-j && dis(a[i], a[j], d)) {
        join(i, j);
      }
    }
  }

  unordered_set<int> cnt;
  for(int i = 1; i <= n; i++) {
    cnt.insert(find(i));
  }

  return cnt.size() == 1;
}

int main() {
  ifstream cin("moocast.in");
  ofstream cout("moocast.out");
  
  cin>>n;

  for(int i = 1; i <= n; i++) {
    cin>>a[i].x>>a[i].y;
  }

  int l = 0, r = pow(25000, 2), ans = 0;
  while(l <= r) {
    int mid = (l+r)/2;
    if(check(mid)) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  cout<<ans<<endl;
  return 0;
} 

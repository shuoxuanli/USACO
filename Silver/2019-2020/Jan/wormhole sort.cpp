#include <bits/stdc++.h>
using namespace std;

struct cow {
  int a, b, w;
};

const int maxN = 1e5 + 1, INF = 1e9+1;
int n, m, perm[maxN], f[maxN], tmp[maxN];
cow c[maxN];

int find(int u) {
  if(f[u] == u) {
    return u;
  }
  f[u] = find(f[u]);
  return f[u];
}

void dsu(int u, int v) {
  int fu = find(u);
  int fv = find(v);
  if(fu != fv) {
    f[fu] = fv;
  }
  return;
}

bool check(int val) {
  for(int i = 1; i <= m; i++) {
    if(c[i].w >= val) {
      dsu(c[i].a, c[i].b);
    }
  }

  for(int i = 1; i <= n; i++) {
    if(find(perm[i]) != find(i)) {
      return false;
    }
  }
  return true;
}


int main() {
  ifstream cin("wormsort.in");
  ofstream cout("wormsort.out");
  
  cin>>n>>m;

  for(int i = 1; i <= n; i++) {
    cin>>perm[i];
    f[i] = i;
  }

  for(int i = 1; i <= m; i++) {
    int a, b, w;
    cin>>a>>b>>w;
    c[i] = {a,b,w};
  }
  
  int l = 0, r = INF, ans = -1;
  while(l <= r) {
    for(int i = 1; i <= n; i++) {
      f[i] = i;
    }
    int mid = (l+r)/2;
    if(check(mid)) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }

  if(ans == INF) cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
} 

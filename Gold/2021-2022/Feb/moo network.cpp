#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())

const int maxN = 1e5+5;
int n, f[maxN];
pll a[maxN];

struct edge {
  int a, b;
  ll w;
};
vector<edge> g;

void add(int u, int v) {
  ll dx = abs(a[u].fi - a[v].fi);
  ll dy = abs(a[u].se - a[v].se);
  g.push_back({u, v, dx*dx+dy*dy});
}

int find(int u) {
  return f[u] == u ? u : f[u] = find(f[u]);
}

int main() {
  cin>>n;
  for(int i = 1; i <= n; i++) {
    cin>>a[i].fi>>a[i].se;
  }
  
  sort(a+1, a+1+n);
  
  vector<int> last(11, -1);
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= 10; j++) {
      if(last[j] != -1) {
        add(i, last[j]);
      }
    }
    last[a[i].se] = i;
  }
  
  iota(f+1, f+1+n, 1);
  sort(g.begin(), g.end(), [](const edge &a, const edge &b) {
    return a.w < b.w;
  });
  
  ll ans = 0; int cnt = 0;
  for(int i = 0; i < sz(g); i++) {
    if(find(g[i].a) != find(g[i].b)) {
      f[find(g[i].a)] = find(g[i].b);
      cnt++;
      ans += g[i].w;
    }
    if(cnt == n-1) break;
  }
  
  cout<<ans<<endl;
  return 0;
}

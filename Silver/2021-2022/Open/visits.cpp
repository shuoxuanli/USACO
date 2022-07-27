#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, a[100001], v[100001], id[100001];
bool vis[100001];
ll ans = 0;

void cycle(int u) {
  int mn = INT_MAX;
  while(!vis[u]) {
    vis[u] = 1;
    ans += v[u];
    mn = min(mn, v[u]);
    u = a[u];
  }
  if(mn != INT_MAX)
    ans -= mn;
}

void del(int u) {
  vis[u] = 1;
  ans += v[u];
  id[a[u]]--;
  if(!id[a[u]] && !vis[a[u]]) 
    del(a[u]);
}

int main() {
  cin>>n;
  for(int i = 1; i <= n; i++) 
    cin>>a[i]>>v[i], id[a[i]]++;
  for(int i = 1; i <= n; i++) {
    if(!id[i] && !vis[i]) del(i);
  }
  for(int i = 1; i <= n; i++) {
    cycle(i);
  }
  cout<<ans<<endl;
  return 0;
}

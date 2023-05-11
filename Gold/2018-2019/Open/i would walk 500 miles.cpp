#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, k;
ll dis[7550];
bool vis[7550];

void prim() {
  for(int i = 1; i <= n; i++) 
    dis[i] = 2019201997;
  for(int i = 0; i < n-1; i++) {
    ll mn = LLONG_MAX; int u = -1;
    for(int j = 1; j <= n; j++) {
      if(!vis[j] && dis[j] < mn) {
        mn = dis[j];
        u = j;
      }
    }
    if(u == -1) continue;
    vis[u] = 1;
    for(int j = 1; j <= n; j++) {
      if(!vis[j]) {
        dis[j] = min(dis[j], (2019201913LL*min(u, j) + 2019201949LL*max(u, j)) % 2019201997LL);
      }
    }
  }
}

int main() {
  ifstream cin("walk.in");
  ofstream cout("walk.out");
  
  cin>>n>>k;
  
  prim();
  
  sort(dis+1, dis+n+1);
  
  cout<<dis[n-k+1]<<endl;
  return 0;
}

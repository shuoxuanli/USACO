#include <bits/stdc++.h>
using namespace std;

struct moo{
  int x, y;
  vector<int>c;
};

moo cows[100001];
bool vis[100001];
int n, m, l = 0, b = 0, r = 0, t = 0;

void dfs(int u) {
  if(vis[u]) {
    return;
  }

  vis[u] = 1;
  for(int j : cows[u].c) {
    if(!vis[j]) {
      l = min(l, cows[j].x);
      r = max(r, cows[j].x);
      t = max(t, cows[j].y);
      b = min(b, cows[j].y);
      dfs(j);
    }
  }
}

int main() {
  ifstream cin("fenceplan.in");
  ofstream cout("fenceplan.out");
  
  cin>>n>>m;

  for(int i = 1; i <= n; i++) {
    cin>>cows[i].x>>cows[i].y;
  }

  for(int i = 0; i < m; i++) {
    int a, b;
    cin>>a>>b;
    cows[a].c.push_back(b);
    cows[b].c.push_back(a);
  }

  int ans = INT_MAX;
  for(int i = 1; i <= n; i++) {
    l = cows[i].x, b = cows[i].y, r = cows[i].x, t = cows[i].y;
    if(!vis[i]) {
      dfs(i);
      ans = min(ans, (r-l)*2 + (t-b)*2);
    }
  }

  cout<<ans<<endl;
  return 0;
} 

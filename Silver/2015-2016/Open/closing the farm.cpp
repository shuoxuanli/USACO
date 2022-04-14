#include <bits/stdc++.h>
using namespace std;

vector<int> v, paths[3001];
bool vis[3001];
int n, m;

void dfs(int u) {
  if(vis[u]) {
    return;
  }
  vis[u] = 1;
  for(int barn: paths[u]) {
    if(!vis[barn]) {
      dfs(barn);
    }
  }
}

int main() {
  freopen("closing.in","r",stdin);
  freopen("closing.out","w",stdout);
  
  cin>>n>>m;
  
  for(int i = 0; i < m; i++) {
    int from, to;
    cin>>from>>to;
    paths[from].push_back(to);
    paths[to].push_back(from);
  }

  dfs(1);
  bool viable = true;
  for(int j = 1; j <= n; j++) {
    if(!vis[j]) {
      viable = false;
      break;
    }
  }

  string ans = viable ? "YES":"NO";
  cout<<ans<<endl;

  for(int i = 0; i < n; i++) {
    int q;
    cin>>q;
    if(i==n-1) break;

    memset(vis, false, sizeof(vis));
    v.push_back(q);
  
    for(int j : v) {
      vis[j] = 1;
    }
    
    for(int j = 1; j <= n; j++) {
      if(!vis[j]) {
        dfs(j);
        break;
      }
    }
    
    viable = true;
    for(int j = 1; j <= n; j++) {
      if(!vis[j]) {
        viable = false;
        break;
      }
    }

    ans = viable ? "YES":"NO";
    cout<<ans<<endl;
  }
  return 0;
} 

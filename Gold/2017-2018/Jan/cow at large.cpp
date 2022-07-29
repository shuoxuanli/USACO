#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n , m , rt , leaf[MAXN] , dep[MAXN];
vector<int> graph[MAXN];

int dfs(int u, int fa) { 
  dep[u] = dep[fa] + 1;
  if(graph[u].size()==1) {
    leaf[u] = dep[u];
    return leaf[u];
  }
  for(int v : graph[u]) {
    if(v == fa) continue;
    leaf[u] = min(leaf[u], dfs(v,u));
  }
  return leaf[u];
}

int dfs2(int u, int fa) {
  if(dep[u] - 1 >= leaf[u] - dep[u]) return 1;
  int cnt = 0;
  for(int v : graph[u]) {
    if(v == fa) continue;
    cnt += dfs2(v,u);
  }
  return cnt;
}

int main() {
  freopen("atlarge.in", "r", stdin);
  freopen("atlarge.out", "w", stdout);
  
  memset(leaf , 0x3f , sizeof(leaf));
  scanf("%d%d" , &n, &rt);
  for(int i = 0; i < n - 1 ; i++) {
    int u, v;
    scanf("%d%d" , &u , &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(rt , 0);
  printf("%d\n" , dfs2(rt, 0));
  return 0;
}

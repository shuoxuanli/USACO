#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define ll long long
struct node {
  int to; 
  ll w;
};

const int maxN = 1e4+1;
int n, m, t;
ll c[maxN], dis[maxN], freqs[maxN], p[maxN];
vector<node> adj[maxN];

void dijkstra() {
  memset(dis, 0x7f, sizeof(dis));
  memset(p, 0x7f, sizeof(p));
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  dis[1] = 0;
  pq.push({dis[1], 1});
  while(!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if(dis[u] != d) continue;
    for(node v : adj[u]) {
      if(dis[v.to] > d + v.w || (dis[v.to] == d+v.w && u < p[v.to])) {
        dis[v.to] = d + v.w;
        p[v.to] = u;
        pq.push({dis[v.to], v.to});
      }
    }
  }
}

void dfs(int u, int v) {
  if(u == 1) return;
  freqs[u] += v;
  dfs(p[u], v);
}

int main() {
  ifstream cin("shortcut.in");
  ofstream cout("shortcut.out");
  
  cin>>n>>m>>t;
  
  for(int i = 1; i <= n; i++) cin>>c[i];

  for(int i = 1; i <= m; i++) {
    int a, b, t;
    cin>>a>>b>>t;
    adj[a].push_back({b,t});
    adj[b].push_back({a,t});
  }
  
  dijkstra();
  
  for(int i = 1; i <= n; i++) {
    dfs(i, c[i]);
  }

  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, freqs[i]*(dis[i]-t));
  }

  cout<<ans<<endl;
  return 0;
} 

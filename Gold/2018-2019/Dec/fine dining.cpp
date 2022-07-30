#include<bits/stdc++.h>
using namespace std;

#define ll long long
struct node {
  int to;
  ll w;
};

int n, m, k;
ll dis[50005], dis2[50005];
vector<node> adj[50005];
bool vis[50005];

void spfa(int src, ll d[]) {
  memset(vis, 0, sizeof(vis));
  d[src] = 0;
  vis[src] = 1;
  queue<int> q;
  q.push(src);
  while(!q.empty()) {
    int from = q.front();
    q.pop();
    vis[from] = 0;
    for(node a : adj[from]) {
      if(d[from] + a.w < d[a.to]) {
        d[a.to] = d[from] + a.w;
        if(!vis[a.to]) {
          q.push(a.to);
          vis[a.to] = 1;
        }
      }
    }
  }
}

int main() {
  ifstream cin("dining.in");
  ofstream cout("dining.out");
  
  cin>>n>>m>>k;
  
  for(int i = 0; i < m; i++) {
    int a, b; ll t;
    cin>>a>>b>>t;
    adj[a].push_back({b,t});
    adj[b].push_back({a,t});
  }

  memset(dis, 0x7f, sizeof(dis));
  spfa(n, dis);

  for(int i = 0; i < k; i++) {
    int p; ll y;
    cin>>p>>y;
    adj[n+1].push_back({p, dis[p]-y});
  }

  memset(dis2, 0x7f, sizeof(dis2));
  spfa(n+1, dis2);

  for(int i = 1; i < n; i++) {
    cout<<(dis2[i]<=dis[i]?1:0)<<endl;
  }

  return 0;
} 

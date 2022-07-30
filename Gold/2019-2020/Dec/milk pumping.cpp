#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define pi pair<int, int>

struct w { 
  ll c, f;
} e[1001][1001];

const int INF = 1e9;
int n, m;
ll dis[1001];

ld dijkstra(int flow) {
  fill(dis+1, dis+1+n, INF);
  dis[1] = 0;
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  pq.push({dis[1],1});
  while(!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if(d != dis[u]) continue;
    for(int j = 1; j <= n; j++) {
      if(e[u][j].f >= flow && dis[j] > d + e[u][j].c) {
        dis[j] = d + e[u][j].c;
        pq.push({dis[j], j});
      }
    }
  }
  return (dis[n] == INF) ? 0 : (ld)flow/dis[n];
}

int main() {
  ifstream cin("pump.in");
  ofstream cout("pump.out");

  cin>>n>>m;
  
  vector<int> flow(m);
  for(int i = 0; i < m; i++) {
    int a, b, c, f;
    cin>>a>>b>>c>>f;
    e[a][b] = {c,f};
    e[b][a] = {c,f};
    flow[i] = f;
  }

  ld res = 0;
  for(int i = 0; i < flow.size(); i++) {
    res = max(res, dijkstra(flow[i]));
  }
  
  ll ans = res*1e6;
  cout<<ans<<endl;
  return 0;
} 

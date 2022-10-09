#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n;
int x[100005], y[100005], dis[100005];
map<int, vector<int>> adj[2];

int main() {
  ifstream cin("lasers.in");
  ofstream cout("lasers.out");
  
  cin>>n>>x[0]>>y[0]>>x[n+1]>>y[n+1];
  
  for(int i = 1; i <= n; i++) {
    cin>>x[i]>>y[i];
  }
  
  for(int i = 0; i <= n+1; i++) {
    adj[0][x[i]].push_back(i);
    adj[1][y[i]].push_back(i);
  }
  
  memset(dis, 0x3f, sizeof(dis));
  queue<pair<int, int>> q;
  q.push({0, 0});
  q.push({0, 1});
  dis[0] = 0;
  
  while(!q.empty()) {
    int u, d;
    tie(u, d) = q.front(), q.pop();
  
    int k = (d == 0 ? x[u] : y[u]);
    for(int v : adj[d][k]) {
      if(dis[u] + 1 < dis[v]) {
        q.push({v, d^1});
        dis[v] = dis[u] + 1;
      }
    }
  }
  
  cout<<(dis[n+1] == 0x3f3f3f3f ? -1 : dis[n+1] - 1)<<'\n';
  return 0;
}

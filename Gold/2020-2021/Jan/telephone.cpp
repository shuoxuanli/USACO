#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())
#define pi pair<int, int>

int n, k;
bool s[55][55];
int a[50005], dis[50005], nn[50005], e[50005][55][2];

int dijkstra() {
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  dis[1] = 0;
  pq.push({dis[1], 1});
  while(!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if(dis[u] != d) continue;
  
    dis[n] = min(dis[n], d+nn[u]);
    for(int j = 1; j <= k; j++) {
      if(u + e[u][j][1] <= n && a[u+e[u][j][1]] == j) {
        int v = u+e[u][j][1];
        if(dis[v] > d + e[u][j][1]) {
          dis[v] = d + e[u][j][1];
          pq.push({dis[v], v});
        }
      }
      if(u - e[u][j][0] > 0 && a[u-e[u][j][0]] == j) {
        int v = u-e[u][j][0];
        if(dis[v] > d + e[u][j][0]) {
          dis[v] = d + e[u][j][0];
          pq.push({dis[v], v});
        }
      }
    }
  }
  return dis[n] == 1e9 ? -1 : dis[n];
}

int main() {
  cin>>n>>k;
  for(int i = 1; i <= n; i++)
    cin>>a[i];
  for(int i = 1; i <= k; i++) {
    string t;
    cin>>t;
    for(int j = 1; j <= k; j++) {
      s[i][j] = t[j-1] == '1';
    }
  }
  
  memset(e, 0x7f, sizeof(e));
  fill(dis+1, dis+1+n, 1e9);
  fill(nn+1, nn+1+n, 1e9);
  
  vector<int> cur(k+1, 1e9);
  for(int i = 1; i <= n; i++) {
    cur[a[i]] = i;
    for(int j = 1; j <= k; j++) {
      if(s[a[i]][j])
        e[i][j][0] = min(e[i][j][0], abs(i-cur[j]));
    }
  }
  
  for(int i = n; i > 0; i--) {
    cur[a[i]] = i;
    for(int j = 1; j <= k; j++) {
      if(s[a[i]][j])
        e[i][j][1] = min(e[i][j][1], abs(i-cur[j]));
    }
  }
  
  for(int i = 1; i <= n; i++) {
    if(s[a[i]][a[n]])
      nn[i] = min(nn[i], n-i);
  }
  
  cout<<dijkstra()<<endl;
  return 0;
}

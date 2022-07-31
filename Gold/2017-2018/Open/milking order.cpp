#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, m, k, deg[100005];
vector<int> ord, adj[100005], edge[50005];

bool sort(int md) {
  ord.clear();
  for(int i = 1; i <= n; i++)
    deg[i] = 0, adj[i].clear();
  for(int i = 0; i < md; i++) {
    for(int j = 1; j < sz(edge[i]); j++) {
      adj[edge[i][j-1]].push_back(edge[i][j]);
      deg[edge[i][j]]++;
    }
  }
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 1; i <= n; i++) 
    if(!deg[i]) pq.push(i);
  while(!pq.empty()) {
    int u = pq.top();
    pq.pop();
    for(int v : adj[u]) {
      if(!(--deg[v]))
        pq.push(v);	
    }
    ord.push_back(u);
  }
  return sz(ord) == n;
}

int main() {
  ifstream cin("milkorder.in");
  ofstream cout("milkorder.out");
  
  cin>>n>>m;
  for(int i = 0; i < m; i++) {
    cin>>k;
    for(int j = 0; j < k; j++) {
      int u; cin>>u;
      edge[i].push_back(u);
    }
  }
  
  int l = 1, r = m;
  vector<int> ans;
  while(l <= r) {
    int mid = (l+r)>>1;
    if(sort(mid)) {	
      ans = ord;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
  
  for(int i = 0; i < n; i++)
    cout<<ans[i]<<" \n"[i==n-1];
  return 0;
}

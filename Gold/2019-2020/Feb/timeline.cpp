#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, m, c;
int a[100005], deg[100005];
vector<int> ord;
vector<pair<int, int>> adj[100005];

void sort() {
  queue<int> q;
  for(int i = 1; i <= n; i++)
    if(!deg[i]) q.push(i);
  
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(auto &v : adj[u]) {
      deg[v.first]--;
      if(!deg[v.first]) 
        q.push(v.first);
    }
    ord.push_back(u);
  }
}

int main() {
  ifstream cin("timeline.in");
  ofstream cout("timeline.out");
  
  cin>>n>>m>>c;
  for(int i = 1; i <= n; i++)
    cin>>a[i];
  for(int i = 0; i < c; i++) {
    int u, v, x;
    cin>>u>>v>>x;
    deg[v]++;
    adj[u].push_back({v, x});
  }
  
  sort();
  
  for(int i = 0; i < n; i++) {
    for(auto &v : adj[ord[i]]) {
      a[v.first] = max(a[v.first], a[ord[i]]+v.second);
    }
  }
  
  for(int i = 1; i <= n; i++) 
    cout<<a[i]<<endl;
  return 0;
}

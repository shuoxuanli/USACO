#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 1e5+5;

struct node {
  ll l, r;
} tree[maxN];

int t, b, n, p[maxN];
ll lo[maxN], hi[maxN], val[maxN];
vector<int> adj[maxN];

void upd(int u) {
  for(int v : adj[u]) {
    lo[v] = min(lo[v], hi[u]);
    hi[v] = max(hi[v], lo[u]);
  }
}

ll solve() {
  for(int i = 2; i <= n; i++) {
    adj[p[i]].push_back(i);
  }
  
  for(int i = 1; i <= n; i++) {
    lo[i] = tree[i].r;
    hi[i] = tree[i].l;
  }

  for(int i = n; i > 1; i--) {
    lo[p[i]] = min(lo[p[i]], lo[i]);
    hi[p[i]] = max(hi[p[i]], hi[i]);
  }
  
  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    lo[i] = min(lo[i], hi[i]);
    if(lo[i] == hi[i]) {
      val[i] = lo[i];
    } else {
      val[i] = max(tree[i].l, min(tree[i].r, (lo[i] + hi[i])/2));
      ans = max(ans, max(hi[i] - val[i], val[i] - lo[i]));
    }
    
    upd(i);
  }
  
  return ans;
}

int main() {
  cin>>t>>b;
  while(t--) {
    cin>>n;
    for(int i = 2; i <= n; i++) {
      cin>>p[i];
    }
    
    for(int i = 1; i <= n; i++) {
      cin>>tree[i].l>>tree[i].r;
    }

    cout<<solve()<<endl;

    if(b) {
      for(int i = 1; i < n; i++) {
        cout<<val[i]<<" ";
      }
      cout<<val[n]<<endl;
    }
    
    for(int i = 1; i <= n; i++) {
      adj[i].clear();
    }
  }
  return 0;
} 

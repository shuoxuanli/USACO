#include <bits/stdc++.h>
using namespace std;

int f[100001]; 

int find(int v) {
  if(f[v] == v) {
    return v;
  }
  f[v] = find(f[v]);
  return f[v];
}

void merge(int u, int v) {
  int fu = find(u);
  int fv = find(v);
  
  if(fu != fv) {
    f[fv] = fu;
  }
  return;
}

int main() {
  ifstream cin("milkvisits.in");
  ofstream cout("milkvisits.out");
  
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  cin>>n>>m;
  
  string s;
  cin>>s;
  
  for(int i=1; i<=n; i++) {
    f[i] = i;
  }
  
  for(int i=1; i<=n-1; i++) {
    int x, y;
    cin>>x>>y;
    if(s[x-1] == s[y-1]) {
      merge(x, y);
    }
  }
  
  for(int i=1; i<=m; i++) {
    int a,b; char c;
    cin>>a>>b>>c;
    if(f[a] == f[b] && s[a-1] != c) {
      cout<<0;
    } else {
      cout<<1;
    }
  }
  return 0;
}

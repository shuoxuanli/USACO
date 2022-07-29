#include <bits/stdc++.h>
using namespace std;

#define ll long long
int a, b, n, m;
int f[2005*2005];

int find(int u) {
  return f[u] == u ? u : f[u] = find(f[u]);
}

void join(int u, int v) {
  int fu = find(u);
  int fv = find(v);
  if(fu != fv) {
    f[fv] = fu;
  }
}

int main() {
  ifstream cin("fencedin.in");
  ofstream cout("fencedin.out");
  
  cin>>a>>b>>n>>m;

  vector<int> v(n+1), h(m+1);
  for(int i = 1; i <= n; i++) {
    cin>>v[i];
  }
  for(int i = 1; i <= m; i++) {
    cin>>h[i];
  }
  
  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++) {
    v[i] = v[i+1] - v[i];
  }
  v[n] = b - v[n];

  sort(h.begin(), h.end());
  for(int i = 0; i < m; i++) {
    h[i] = h[i+1] - h[i];
  }
  h[m] = a - h[m];
  
  sort(v.begin(), v.end());
  sort(h.begin(), h.end());
  n++, m++;
  iota(f, f+n*m, 0);
  
  ll ans = 0;
  for(int i = 0, j = 0; i < n || j < m;) {
    if(j == m || (i < n && v[i] < h[j])) {
      for(int k = 0; k < m-1; k++) {
        if(find(i*m+k) != find(i*m+k+1)) {
          join(i*m+k, i*m+k+1);
          ans += v[i];
        }
      }
      i++;
    } else {
      for(int k = 0; k < n-1; k++) {
        if(find(k*m+j) != find((k+1)*m+j)) {
          join(k*m+j, (k+1)*m+j);
          ans += h[j];
        }
      }
      j++;
    }
  }

  cout<<ans<<endl;
  return 0;
} 

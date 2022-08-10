#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, a[2505], dep[2505];
vector<int> adj[2505];
bool b = 1;

void dfs(int u, int p) {
  dep[u] = dep[p]+1;
  for(int v : adj[u]) {
    if(v^p)
      dfs(v, u);	
  }
}

int main() {
  ifstream cin("clocktree.in");
  ofstream cout("clocktree.out");
  cin>>n;
  for(int i = 1; i <= n; i++)
    cin>>a[i];
  for(int i = 0; i < n-1; i++) {
    int u, v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  int sum1 = 0, sum2 = 0, n1 = 0, n2 = 0;
  for(int i = 1; i <= n; i++) {
    if(dep[i]&1) sum1 += a[i], n1++;
    else sum2 += a[i], n2++;
  }
  if(sum1%12 == sum2%12)
    cout<<n<<endl;
  else if((sum1+1)%12 == sum2%12)
    cout<<n2<<endl;
  else if(sum1%12 == (sum2+1)%12)
    cout<<n1<<endl;
  else
    cout<<0<<endl;
  return 0;
}

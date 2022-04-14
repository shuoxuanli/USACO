#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
vector<int> adj[maxN];
bool col[maxN];
int n, m, comp[maxN], num = 0;

void dfs(int u) {
  if(comp[u]) {
    return;
  }
  comp[u] = num;
  for(int j : adj[u]) {
    if(col[j] == col[u]) {
      dfs(j);
    }
  }
}

int main() {
  ifstream cin("milkvisits.in");
  ofstream cout("milkvisits.out");

  cin>>n>>m;
  string s; cin>>s;

  for(int i = 1; i <= n; i++) {
    col[i] = s[i-1]=='G';
  }

  for(int i = 0; i < n-1; i++) {
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <= n; i++) {
    if(!comp[i]) {
      num++;
      dfs(i);
    }
  }

  string ans = "";
  for(int i = 0; i < m; i++) {
    int st, ed; char c;
    cin>>st>>ed>>c;
    if(col[st] == (c=='G') || comp[st] != comp[ed]) {
      ans += '1';
    } else {
      ans += '0';
    }
  }

  cout<<ans<<endl;
  return 0;
} 

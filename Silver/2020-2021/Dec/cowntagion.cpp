#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
vector<int> adj[maxN];
int cnt[maxN], ans = 0;
bool vis[maxN];

int calc(int num, int target) {
  int ret = 0;
  while(num < target) {
    num*=2;
    ret++;
  }
  return ret;
}

void bfs(int u) {
  queue<int> q;
  q.push(u);
  while(!q.empty()) {
    int t = q.front();
    q.pop();

    if(vis[t]) {
      continue;
    }

    vis[t] = 1;
    int cnt = 0;
    for(int j : adj[t]) {
      if(!vis[j]) {
        q.push(j);
        cnt++;
      }
    }

    ans += calc(1, cnt+1);
    ans += cnt;
  }
}

int main() {
  int n;
  cin>>n;

  for(int i = 0; i < n-1; i++) {
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bfs(1);

  cout<<ans<<endl;
  return 0;
} 

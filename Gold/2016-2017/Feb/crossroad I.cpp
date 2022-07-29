#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct point{
  int to;
  ll w;
};

ll t, mat[105][105], dis[10050];
bool vis[10050];
int dx[16] = {3,-3,2,-2,2,-2,1,-1,1,-1,0,0,1,-1,0,0};
int dy[16] = {0,0,1,-1,-1,1,2,-2,-2,2,3,-3,0,0,1,-1};
vector<point> adj[10050];

int main() {
  ifstream cin("visitfj.in");
  ofstream cout("visitfj.out");

  int n;
  cin>>n>>t;
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin>>mat[i][j];
    }
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      for(int k = 0; k < 16; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx < 1 || ny < 1) continue;
        if((nx-1)*n+ny > n*n && (n-i)+(n-j) < 3) 
          adj[(i-1)*n+j].push_back({n*n, t*((n-i)+(n-j))});
        else if (nx <= n && ny <= n)
          adj[(i-1)*n+j].push_back({(nx-1)*n+ny, mat[nx][ny]+t*3});
      }
    }
  }
  
  memset(dis, 0x7f, sizeof(dis));
  queue<int> q; q.push(1);
  dis[1] = 0;
  vis[1] = 1;
  while(!q.empty()) {
    int from = q.front();
    q.pop();
    vis[from]=0;
    for(int i = 0; i < adj[from].size(); i++) {
      int to = adj[from][i].to;
      int w = adj[from][i].w;
      if(dis[from] + w < dis[to]) {
        dis[to] = dis[from] + w;
        if(!vis[to]) {
          q.push(to);
          vis[to] = 1;
        }
      }
    }	
  }

  cout<<dis[n*n]<<endl;
  return 0;
} 

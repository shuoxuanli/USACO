#include <bits/stdc++.h>
using namespace std;

struct moocast{
  int x, y, p;
};

moocast wk[201];
bool vis[201];
int n, ans = 0, tmp = 1;

bool distance(int x, int y, int x2, int y2, int p) {
  return sqrt(pow(x2-x,2) + pow(y2-y,2)) <= double(p);
}
void dfs(int r) {
  if(vis[r]) {
    return;
  }

  int a = wk[r].x;
  int b = wk[r].y;
  int p = wk[r].p;

  vis[r] = 1;
  for(int i = 0; i < n; i++) {
    if(distance(a,b,wk[i].x, wk[i].y, p) && !vis[i]) {
      tmp++;
      dfs(i);
    }
  }
}

int main() {
  ifstream cin("moocast.in");
  ofstream cout("moocast.out");
  
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>wk[i].x>>wk[i].y>>wk[i].p;
  }

  for(int i = 0; i < n; i++) {
    tmp = 1;
    dfs(i);
    ans = max(ans, tmp);
    memset(vis, false, sizeof(vis));
  }

  cout<<ans<<endl;
  return 0;
} 

#include <bits/stdc++.h>
using namespace std;

int n;
int from[101], to[101]; 
bool vis[101], viable[101];

int dfs(int index) {
  int cnt = 0;
  int c = 0;
  while(c < n) {
    if(c==0) {
      for(int i = 0; i < n-1; i++) {
        if(to[i] == index) {
          cnt++;
          viable[from[i]] = true;
          vis[i] = true;
        }
      }
    } else {
      for(int i = 0; i < n-1; i++) {
        if(!vis[i] && viable[to[i]]) {
          cnt++;
          viable[from[i]] = true;
          vis[i] = true;
        }
      }
    }
    if(cnt == n-1) {
      break;
    }
    c++;
  }
  return cnt;
}

int main() {
  freopen("factory.in", "r", stdin);
  freopen("factory.out", "w", stdout);

  cin>>n;
  for(int i = 0; i < n-1; i++) {
    cin>>from[i]>>to[i];
  }

  for(int i = 1; i < n; i++) {
    memset(vis, false, sizeof(vis));
    memset(viable, false, sizeof(viable));
    int temp = dfs(i);
    if(temp == n-1) {
      cout<<i<<endl;
      return 0;
    } 
  }
  
  cout<<-1<<endl;
  return 0;
} 

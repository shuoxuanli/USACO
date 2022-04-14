#include <bits/stdc++.h>
using namespace std;

int n, b, tiles[251], boots[251][2];
int ans = INT_MAX;
bool walked[251][251];

void dfs(int t, int bt) {
  if(bt == b) {
    return;
  }
  if(t == n-1) {
    ans = min(ans, bt);
    return;
  }

  for(int i = 1; i <= boots[bt][1]; i++) {
    if(t + i < n && tiles[t+i] <= boots[bt][0] && !walked[t+i][bt]) {
      walked[t+i][bt] = 1;
      dfs(t+i, bt);
    }
  }

  for(int i = bt+1; i < b; i++) {
    if(boots[i][0] >= tiles[t] && !walked[t][i]) {
      walked[t][i] = 1;
      dfs(t, i);
    }
  }
}

int main() {

  freopen("snowboots.in", "r", stdin);
  freopen("snowboots.out", "w", stdout);

  cin>>n>>b;

  for(int i = 0; i < n; i++) {
    cin>>tiles[i];
  }

  for(int i = 0; i < b; i++) {
    cin>>boots[i][0]>>boots[i][1];
  }

  dfs(0,0);

  cout<<ans<<endl;
} 

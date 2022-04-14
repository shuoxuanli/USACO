#include<bits/stdc++.h>
using namespace std;

int x[101], y[101];

int main() {
  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  int n, b;
  cin>>n>>b;

  for(int i = 0; i < n; i++){
    cin>>x[i]>>y[i];
  }

  int ans = INT_MAX;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int temp = 0;
      int dx = x[i]+1;
      int dy = y[j]+1;
      int ld = 0, rd = 0, lp = 0, rp = 0;
      for(int k = 0; k < n; k++) {
        if(x[k] < dx && y[k] < dy) {
          ld++;
        }
        else if(x[k] > dx && y[k] < dy) {
          rd++;
        }
        else if(x[k] < dx && y[k] > dy) {
          lp++;
        }
        else if(x[k] > dx && y[k] > dy) {
          rp++;
        }
      }
      temp = max(ld, max(rd, max(lp, rp)));
      ans = min(temp, ans);
    }
  }
  cout<<ans<<endl;
  return 0;
} 

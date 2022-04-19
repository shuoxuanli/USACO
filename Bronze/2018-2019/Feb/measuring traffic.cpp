#include<bits/stdc++.h>
using namespace std;

int lr[101][2], curr[2], ans[2][2];
string ramp[101];

int main() {
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>ramp[i]>>lr[i][0]>>lr[i][1];
  }
  
  int count = 0;
  for(int i = 0; i < n; i++) {
    if(ramp[i] == "none") {
      if(count == 0) {
        curr[0] = lr[i][0];
        curr[1] = lr[i][1];
      }
      else {
        curr[0] = max(lr[i][0], curr[0]);
        curr[1] = min(lr[i][1], curr[1]);
      }
      count++;
    }
    else if(ramp[i] == "on") {
      curr[0] += lr[i][0];
      curr[1] += lr[i][1];
    }
    else if(ramp[i] == "off") {
      curr[0] -= lr[i][1];
      curr[1] -= lr[i][0];
      curr[0] = max(curr[0], 0);
      curr[1] = max(curr[1], 0);
    }
  }
  ans[1][0] = curr[0];
  ans[1][1] = curr[1];

  for(int i = n-1; i >= 0; i--) {
    if(ramp[i] == "none") {
        curr[0] = max(lr[i][0], curr[0]);
        curr[1] = min(lr[i][1], curr[1]);
    }
    else if(ramp[i] == "on") {
      curr[0] -= lr[i][1];
      curr[1] -= lr[i][0];
      curr[0] = max(curr[0], 0);
      curr[1] = max(curr[1], 0);
    }
    else if(ramp[i] == "off") {
       curr[0] += lr[i][0];
       curr[1] += lr[i][1];
    }
  }
  ans[0][0] = curr[0];
  ans[0][1] = curr[1];

  cout<<ans[0][0]<<" "<<ans[0][1]<<endl;
  cout<<ans[1][0]<<" "<<ans[1][1]<<endl;
  return 0;
} 

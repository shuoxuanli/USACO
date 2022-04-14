#include <bits/stdc++.h>
using namespace std;

int locx[3], locy[3];

int main() {
  freopen("buckets.in", "r", stdin);
  freopen("buckets.out", "w", stdout);

  for(int i = 1; i <= 10; i++) {
    for(int j = 1; j <= 10; j++) {
      char s;
      cin>>s;
      if(s == 'B') {
        locx[0] = j;
        locy[0] = i;
      }
      else if(s == 'L') {
        locx[1] = j;
        locy[1] = i;
      }
      else if(s == 'R') {
        locx[2] = j;
        locy[2] = i;
      }
    }
  }

  int ans = 0;
  if(locx[0] == locx[2] && locx[0] == locx[1] && locy[1] > locy[2] && locy[2] > locy[0]) {
    ans += 2;
  }
  else if(locx[0] == locx[2] && locx[0] == locx[1] && locy[1] < locy[2] && locy[2] < locy[0]) {
    ans += 2;
  }
  else if(locy[0] == locy[2] && locy[0] == locy[1] && locx[1] > locx[2] && locx[2] > locx[0]) {
    ans += 2;
  }
  else if(locy[0] == locy[2] && locy[0] == locy[1] && locx[1] < locx[2] && locx[2] < locx[0]) {
    ans += 2;
  }

  ans += abs(locx[1] - locx[0]) + abs(locy[1] - locy[0]) - 1;

  cout<<ans<<endl;
  return 0;
} 

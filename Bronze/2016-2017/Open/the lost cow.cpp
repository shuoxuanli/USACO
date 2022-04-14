#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);

  int x, y;
  cin>>x>>y;

  int pos = x;
  int pre = x;
  int ans = 0;


  if(x == y) {
    cout<<0<<endl;
    return 0;
  }
  else if(x < y) {
    int distance = 1;
    while(pos < y) {
      pos = x + distance;
      ans += abs(pos - pre);
      pre = pos;
      distance *= -2;
    }
    ans -= abs(pos-y);
  } else {
     int distance = 1;
     while(pos > y) {
      pos = x + distance;
      ans += abs(pos - pre);
      pre = pos;
      distance *= -2;
     }
    ans -= abs(pos-y);
  }


  cout<<ans<<endl;
  return 0;
} 

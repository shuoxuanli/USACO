#include<bits/stdc++.h>
using namespace std;

int n, k;

int minTime(int cap) {
  int up = 0, down = 0;
  int speed = 1, t = 0;
  while(up + down < k) {
    up += speed;
    t++;
    if(up + down >= k) {
      return t;
    }
    if(speed >= cap) {
      down += speed;
      t++;
      if(up + down >= k) {
        return t;
      }
    } 
    speed++;
  }
  return -1;
}

int main() {
  freopen("race.in", "r", stdin);
  freopen("race.out", "w", stdout);

  cin>>k>>n;

  int x;
  for(int i = 0; i < n; i++) {
    cin>>x;
    cout<<minTime(x)<<endl;
  }
} 

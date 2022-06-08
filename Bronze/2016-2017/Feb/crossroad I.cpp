#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);

  int n;
  cin>>n;

  map<int, int> map;

  int ans = 0;
  for(int i = 0; i < n; i++) {
   int cow, road;
   cin>>cow>>road;
   if(map.count(cow) && road != map[cow]) {
     ans++;
   }
   map[cow] = road;
  }

  cout<<ans<<endl;
  return 0;
} 

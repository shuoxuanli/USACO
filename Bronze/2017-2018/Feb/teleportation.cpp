#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("teleport.in", "r", stdin);
  freopen("teleport.out", "w", stdout);

  int a, b, x, y;
  cin>>a>>b>>x>>y;

  int d1 = max(b,a) - min(b,a);
  int d2 = abs(min(x,y)-min(b,a)) + abs(max(b,a)-max(x,y));

  int ans = min(d1, d2);

  cout<<ans<<endl;
} 

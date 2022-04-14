#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);
  
  int x,y,m;
  cin>>x>>y>>m;

  if(m%x == 0 || m%y == 0 || m%(x+y)==0) {
    cout<<m<<endl;
    return 0;
  }

  int ans = 0;
  for(int i = 0; i <= m/x; i++) {
    for(int j = 0; j <= m/y; j++) {
      int product = i*x + j*y;
      if(product > m) {
        break;
      }
      else if(product == m) {
        cout<<m<<endl;
        return 0;
      }
      else if (product < m){
        ans = max(product, ans);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
} 

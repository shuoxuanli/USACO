#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  string s;
  cin>>s;
    
  int ans = 0;
  for(int i = n-1; i >= 1; i -= 2) {
    if(s[i] == s[i-1]) continue;
    if(s[i] == 'G' && ans%2==1) ans++;
    if(s[i] == 'H' && ans%2==0) ans++;
  }
  
  cout<<ans<<endl;
  return 0;
}

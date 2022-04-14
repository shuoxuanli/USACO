#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("citystate.in", "r", stdin);
  freopen("citystate.out", "w", stdout);

  int n;
  cin>>n;

  int ans = 0;
  unordered_map <string, int> mp;
  for(int i = 0; i < n; i++) {
    string city, code;
    cin>>city>>code;
    city = city.substr(0,2);

    if(city != code) {
      ans += mp[code + city];
    }
    mp[city + code]++;
  }

  cout<<ans<<endl;
  return 0;
} 

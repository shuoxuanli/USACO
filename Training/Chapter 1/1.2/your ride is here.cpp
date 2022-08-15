/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: ride
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);

  int comet = 0;
  int group = 0;
  for(int i = 0; i < 2; i++) {
    string s;
    cin>>s;
    int product = 1;
    for(int j = 0; j < s.length(); j++) {
      product *= s[j] - 'A' + 1;
    }
    if(i==0) {
      comet = product % 47;
    } 
    else {
      group = product % 47;
    }
  } 

  string ans = (comet==group) ? "GO":"STAY";
  cout<<ans<<endl;
} 

/*
 ID: shuoxua2
 PROG: prefix
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

string p, s;
vector<string> v;
int dp[200001];

int main() {
  ifstream cin("prefix.in");
  ofstream cout("prefix.out");
  
  while(cin>>p && p != ".") {
    v.push_back(p);
  }
  
  while(cin>>p) s+=p;

  dp[0] = 1;
  for(int i = 0; i < s.length(); i++) {
    if(dp[i]) {
      for(int j = 0; j < v.size(); j++) {
        if(s.substr(i, v[j].length()) == v[j]) {
          dp[i+v[j].length()]++;
        }
      }
    }
  }

  int ans = s.length();
  while(!dp[ans] && ans > 0) ans--;

  cout<<ans<<endl;
  return 0;
} 

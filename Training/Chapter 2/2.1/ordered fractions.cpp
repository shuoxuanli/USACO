/*
 ID: shuoxua2
 PROG: frac1
 LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
int n;
vector<pi> ans;

int gcd(int a, int b) {
  if(a%b == 0) {
    return b;
  }
  return gcd(b, a%b);
}

int main() {
  ifstream cin("frac1.in");
  ofstream cout("frac1.out");
  
  cin>>n;

  for(int i = 0; i <= n; i++) {
    for(int j = n; j > 0; j--) {
      if(i == 1) {
        ans.push_back({i,j});
      }
      else if(double(i)/j <= 1 && gcd(i,j) == 1) {
        ans.push_back({i,j});
      }
    }
  }

  sort(ans.begin(), ans.end(), [] (pi a, pi b) {
    return double(a.first)/a.second < double(b.first)/b.second;
  });

  for(pi v : ans) cout<<v.first<<"/"<<v.second<<endl;
  return 0;
} 

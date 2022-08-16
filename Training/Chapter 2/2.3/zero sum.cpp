/*
 ID: shuoxua2
 PROG: zerosum
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int n;
set<string> ans;

void dfs(int sum, int m, string s) {
  if(m == n+1 && sum == 0) {
    ans.insert(s);
    return;
  }
  else if(m > n) return;
  
  string tmp;

  tmp = s + "+" + to_string(m);
  dfs(sum+m, m+1, tmp);

  tmp = s + "-" + to_string(m);
  dfs(sum-m, m+1, tmp);
  
  tmp = s + "+" + to_string(m) + " " + to_string(m+1);
  dfs(sum+m*10+m+1, m+2, tmp);

  tmp = s + "-" + to_string(m) + " " + to_string(m+1);
  dfs(sum-(m*10+m+1), m+2, tmp);
}

int main() {
  ifstream cin("zerosum.in");
  ofstream cout("zerosum.out");
  
  cin>>n;

  dfs(1, 2, "1");
  dfs(12, 3, "1 2");
  
  for(string s : ans) cout<<s<<endl;
  return 0;
} 

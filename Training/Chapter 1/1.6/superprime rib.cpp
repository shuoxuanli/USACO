/*
ID: shuoxua2
LANG: C++
TASK: sprime
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

bool prime(int a) {
  for(int i = 2; i <= sqrt(a); i++) {
    if(a%i == 0) return 0;
  }
  return 1;
}

void dfs(int a, int k) {
  if(k == n) {
    ans.push_back(a);
    return;
  }

  for(int i = 1; i <= 9; i += 2) {
    if(prime(10*a+i)) dfs(10*a+i, k+1);
  }
}

int main() {
  ifstream cin("sprime.in");
  ofstream cout("sprime.out");
  cin>>n;
  for(int i = 2; i <= 9; i++) {
    if(prime(i)) dfs(i, 1);
  }
  
  for(int v : ans) cout<<v<<endl;
  return 0;
} 

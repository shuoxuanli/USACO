#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
int n, a[maxN], last[maxN];
stack<int> stk;
unordered_set<int> s;

int main() {
  ifstream cin("art2.in");
  ofstream cout("art2.out");
  
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>a[i];
    last[a[i]] = i;
  }
  
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(!a[i]) {
      while(!stk.empty()) stk.pop();
      continue;
    }
    if(!s.count(a[i])) {
      stk.push(a[i]);
      s.insert(a[i]);
      ans = max((int)stk.size(), ans);
    }
    if(stk.empty() || stk.top() != a[i]) {
      ans = -1;
      break;
    } 
    if(last[a[i]] == i) {
      stk.pop();
      s.erase(a[i]);
    }
  }

  cout<<ans<<endl;
  return 0;
} 

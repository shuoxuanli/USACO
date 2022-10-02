#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, a[300005];

int main() {
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  stack<pair<int, int>> stk;
  stk.push({a[0], 0});
  ll ans = 0;
  for(int i = 1; i < n; i++) {
    while(!stk.empty() && stk.top().first < a[i]) {
      ans += (i - stk.top().second + 1);
      stk.pop();
    }
    if(!stk.empty())
      ans += (i - stk.top().second + 1);
    stk.push({a[i], i});
  }
  cout<<ans<<endl;
  return 0;
}

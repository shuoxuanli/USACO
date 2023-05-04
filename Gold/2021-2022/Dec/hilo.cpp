#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 2E5 + 1;
int n, a[N], p[N];
stack<int> stk[N];
bool taken[N];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[a[i]] = i;
  }

  stack<int> dec;
  for (int i = n; i >= 1; i--) {
    while (!dec.empty() && dec.top() > p[i]) {
      stk[i].push(dec.top());
      dec.pop();
    }
    dec.push(p[i]);
  }

  int ans = 0;
  cout << ans << '\n';

  stack<int> inc;
  for (int i = 1; i <= n; i++) {
    if (!inc.empty() && (dec.empty() || dec.top() < inc.top())) {
      ans--;
    }

    while (!inc.empty() && inc.top() > p[i]) inc.pop();
    if (!dec.empty()) inc.push(dec.top()), dec.pop();

    if (!dec.empty() && (inc.empty() || (inc.top() > dec.top() && !taken[dec.top()]))) {
      ans++;
      taken[dec.top()] = true;
    }

    while (!stk[i].empty()) dec.push(stk[i].top()), stk[i].pop();
    cout << ans << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
int n, a[maxN], b[maxN], ma[maxN], mb[maxN];

int main() {
  cin>>n;

  for(int i = 1; i <= n; i++) {
    cin>>a[i];
    ma[a[i]] = i;
  }

  for(int i = 1; i <= n; i++) {
    cin>>b[i];
    mb[b[i]] = i;
  }

  for(int i = 1; i <= n; i++) {
    if(ma[a[i-1]] > mb[a[i]]) {
      ma[a[i]] = ma[a[i-1]];
    } else {
      ma[a[i]] = mb[a[i]];
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(ma[b[i]] > i) ans++;
  }

  cout<<ans<<endl;
  return 0;
}

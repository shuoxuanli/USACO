#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct stop{
  int x, c;
};

stop rest[1000001];
bool mxn[100001];

int main() {
  freopen("reststops.in", "r", stdin);
  freopen("reststops.out", "w", stdout);

  int l, n, f, b;
  cin>>l>>n>>f>>b;

  for(int i = 0; i < n; i++) {
    cin>>rest[i].x>>rest[i].c;
  }

  int last = 0;
  for(int i = n-1; i >= 0; i--) {
    if(rest[i].c > last) {
      mxn[i] = 1;
      last = rest[i].c;
    }
  }

  ll ans = 0;
  int lastd = 0;
  for(int i = 0;i < n; i++) {
    if(mxn[i]) {
      ans += (ll)(rest[i].x - lastd)*(ll)(f-b)*(ll)(rest[i].c);
      lastd = rest[i].x;
    }
  }

  cout<<ans<<endl;
  return 0;
} 

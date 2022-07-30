#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 1e5+1;
ll n, c[maxN], cnt[maxN];

int lowbit(int x) {
  return x &(-x);
}

void upd(int x, int v) {
  for(int i = x; i <= n; i+=lowbit(i)) {
    c[i] += v;
  }
}

ll qry(int x) {
  ll ret = 0;
  for(int i = x; i > 0; i-=lowbit(i)) {
    ret += c[i];
  }
  return ret;
}

int main() {
  ifstream cin("haircut.in");
  ofstream cout("haircut.out");
  
  cin>>n;

  for(int i = 0; i < n; i++) {
    int a;
    cin>>a, a++;
    cnt[a] += i - qry(a);
    upd(a, 1);
  }

  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    cout<<ans<<endl;
    ans += cnt[i];
  }
  return 0;
} 

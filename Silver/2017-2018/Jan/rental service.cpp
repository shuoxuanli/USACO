#include <bits/stdc++.h>
using namespace std;

#define ll long long
using pi = pair<ll, ll>;

const int maxN = 1e5+1;
ll n,m,r,milk[maxN], rent[maxN], pm[maxN], pr[maxN];

struct sell{
  ll p, amt;
};

sell price[maxN];

bool cmp(sell a, sell b) {
  return a.p > b.p;
}

int main() {
  freopen("rental.in", "r", stdin);
  freopen("rental.out", "w", stdout);

  cin>>n>>m>>r;

  for(int i = 0; i < n; i++) {
    cin>>milk[i];
  }

  for(int i = 0; i < m; i++) {
    cin>>price[i].amt>>price[i].p;
  }

  for(int i = 0; i < r; i++) {
    cin>>rent[i];
  }

  sort(milk, milk+n, greater<int>());
  sort(price, price + m, cmp);
  sort(rent, rent + r, greater<int>());


  int p = 0; 
  ll dec = 0; 
  for(int i = 1; i <= n; i++) {
    pm[i] = pm[i-1];
    while(milk[i-1] > 0 && p < m) {
      ll tmp = min(milk[i-1], price[p].amt - dec);
      pm[i] += tmp*price[p].p;
      if(price[p].amt - dec == tmp) {
        p++;
        dec = 0;
      }
      else if(price[p].amt - dec > milk[i-1]) {
        dec += milk[i-1];
      } 
      milk[i-1] -= tmp;
    }
  }

  for(int i = 1; i <= n; i++) {
    pr[i] = pr[i-1] + rent[i-1];
  }

  ll ans = 0;
  for(int i = 0; i <= n; i++) {
    ans = max(ans, pm[i] + pr[n-i]);
  }

  cout<<ans<<endl;
  return 0;
}  

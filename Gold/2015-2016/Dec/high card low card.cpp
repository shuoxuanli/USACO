#include <bits/stdc++.h>
using namespace std;

int n;
bool c[500001], t[500001];
vector<int> f, s, a;

int main() {
  ifstream cin("cardgame.in");
  ofstream cout("cardgame.out");
  
  cin>>n;

  for(int i = 0; i < n; i++) {
    int d; cin>>d;
    c[d] = 1;
    if(i < n/2) f.push_back(d);
    else s.push_back(d);
  }

  for(int i = 1; i <= n*2; i++) {
    if(!c[i]) a.push_back(i);
  }

  sort(f.begin(), f.end());
  sort(s.begin(), s.end());
  sort(a.begin(), a.end());

  int i = n-1, j = n/2-1, ans = 0;
  while(i >= 0 && j >= 0) {
    while(j >= 0 && a[i] < f[j]) j--;
    if(j >= 0) {
      ans++;
      t[a[i]] = 1;
    }
    i--, j--;
  }

  i = n-1, j = n/2-1;
  while(i >= 0 && j >= 0) {
    while(i >= 0 && (a[i] > s[j] || t[a[i]])) i--;
    if(i >= 0) ans++;
    i--, j--;
  }

  cout<<ans<<endl;
  return 0;
}

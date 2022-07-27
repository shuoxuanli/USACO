#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream cin("haybales.in");
  ofstream cout("haybales.out");
  
  int n, q;
  cin>>n>>q;

  vector<int> bales(n);
  for(int i = 0; i < n; i++) {
    cin>>bales[i];
  }

  sort(begin(bales), end(bales));

  for(int i = 0; i < q; i++) {
    int a, b; 
    cin>>a>>b;
    auto hi = upper_bound(begin(bales), end(bales), b);
    auto lo = lower_bound(begin(bales), end(bales), a);
    cout<<hi-lo<<endl;
  }
  return 0;
}

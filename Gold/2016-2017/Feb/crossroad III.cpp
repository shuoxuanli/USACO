#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 5e4+1;
int n, freqs[maxN], c[2*maxN], last[maxN];

int lowbit(int x) {
  return x&(-x);
}

void upd(int x, int v) {
  for(int i = x; i <= 2*n; i+=lowbit(i)) {
    c[i] += v;
  }
}

ll qry(int x) {
  ll ret = 0;
  for(int i = x; i > 0; i -= lowbit(i)) {
    ret += c[i];
  }
  return ret;
}

int main() {
  ifstream cin("circlecross.in");
  ofstream cout("circlecross.out");
  
  cin>>n;

  ll ans = 0;
  for(int i = 1; i <= 2*n; i++) {
    int a; cin>>a;
    freqs[a]++;
    if(freqs[a] == 1) {
      upd(i, 1);
      last[a] = i;
    }
    if(freqs[a] == 2) {
      upd(last[a], -1);
      ans += qry(i)-qry(last[a]);
    }
  }

  cout<<ans<<endl;
  return 0;
} 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
string s;
ll n;

char rot(ll m) {
  ll len = s.length();
  if(m < len) {
    return s[m];
  }

  while(len*2ll <= m) {
    len *= 2ll;
  }

  if(m == len) {
    return rot(m-1ll);
  } else {
    return rot(m-len-1ll);
  }
}

int main() {
  freopen("cowcode.in", "r", stdin);
  freopen("cowcode.out", "w", stdout);

  cin>>s;
  cin>>n;

  cout<<rot(n-1)<<endl;
  return 0;
} 

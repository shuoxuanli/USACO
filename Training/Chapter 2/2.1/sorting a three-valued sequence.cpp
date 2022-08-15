/*
 ID: shuoxua2
 PROG: sort3
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int n, a[1001], s[1001];

int main() {
  ifstream cin("sort3.in");
  ofstream cout("sort3.out");
  
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>a[i];
  }

  memcpy(s, a, sizeof(s));
  
  sort(s, s+n);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] != a[i]) {
      for(int j = i+1; j < n; j++) {
        if(s[j] == a[i] && a[j] == s[i]) {
          ans++;
          swap(a[i], a[j]);
        }
      }
    }
  }

  for(int i = 0; i < n; i++) {
    if(s[i] != a[i] && a[i] == 1) {
      ans += 2;
    }
  }

  cout<<ans<<endl;
  return 0;
}

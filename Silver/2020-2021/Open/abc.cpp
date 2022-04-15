#include <bits/stdc++.h>
using namespace std;

int t, n, m[7];

int check() {
  int ret = 0;
  unordered_set<int> comb;
  for(int i = 0; i < n; i++) {
    comb.insert(m[i]);
    for(int j = 0; j < n; j++) {
      if(m[i] != m[j]) comb.insert(abs(m[i]-m[j]));
    }
  }

  for(int a : comb) {
    for(int b : comb) {
      for(int c : comb) {
        if(a <= b && b <= c) {
          bool found = 1;
          unordered_set<int> s = {a, b, c, a+b, b+c, a+c, a+b+c};
          for(int i = 0; i < n; i++) {
            if(!s.count(m[i])) found = 0;
          }
          if(found) ret++;
        }
      }
    }
  }
  return ret;
}

int main() {
  cin>>t;

  while(t--) {
    cin>>n;
    for(int i = 0; i < n; i++) cin>>m[i];
    cout<<check()<<endl;
  }
  return 0;
} 

#include<bits/stdc++.h>
using namespace std;

bool rep[101];

int main() {
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);

  int n;
  cin>>n;

  string s;
  cin>>s;

  for(int k = n-2; k >= 0; k--) {
    for(int i = 0; i <= n - k; i++) {
      for(int j = 0; j <= n - k; j++) {
        if(s.substr(i, k) == s.substr(j, k) && i != j) {
          cout<<k+1<<endl;
          return 0;
        }
      }
    }
  }
} 

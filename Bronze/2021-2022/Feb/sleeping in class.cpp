#include <bits/stdc++.h>
using namespace std;

int t, n, a[100001];

int main() {
  cin>>t;
  while(t--) {
    cin>>n;

    int sum = 0;
    for(int i = 0; i < n; i++) {
      cin>>a[i];
      sum += a[i];
    }

    for(int i = n; i > 0; i--) {
      if(sum % i != 0) {
        continue;
      }
      int tar = sum/i, cur = 0;
      bool b = 1;
      for(int j = 0; j < n; j++) {
        cur += a[j];
        if(tar == cur) cur = 0;
        if(cur > tar) b = 0;
      }
      if(b) {
        cout<<n-i<<endl;
        break;
      }
    }
  }
  return 0;
} 

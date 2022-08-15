/*
 ID: shuoxua2
 PROG: hamming
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int n, b, d;
vector<int> v;

int main() {
  ifstream cin("hamming.in");
  ofstream cout("hamming.out");
  
  cin>>n>>b>>d;

  for(int i = 0; i <= (1<<b); i++) {
    bool flag = 1;
    for(int j = 0; j < v.size(); j++) {
      int m = 0;
      for(int k = 0; k < b; k++) {
        if((v[j]&(1<<k))^(i&(1<<k))) 
          m++;
      }
      if(m < d) {
        flag = 0;
        break;
      }
    }
    if(flag) v.push_back(i);
  }

  for(int i = 0, j = 1; i < n; i++, j++) {
    if(j % 10 == 0 || i == n-1) cout<<v[i]<<endl;
    else cout<<v[i]<<" ";
  }
} 

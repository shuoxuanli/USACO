#include <bits/stdc++.h>
using namespace std;

int n, a[100001], base[100001];
stack<int> stk[100001];

int main() {
  ifstream cin("dishes.in");
  ofstream cout("dishes.out");
  
  cin>>n;

  for(int i = 0; i < n; i++) cin>>a[i];

  int p = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] < p) {
      cout<<i<<endl;
      return 0;
    }
    for(int j = a[i]; j > 0 && !base[j]; j--) {
      base[j] = a[i];
    }
    while(!stk[base[a[i]]].empty() && stk[base[a[i]]].top() < a[i]) {
      p = stk[base[a[i]]].top();
      stk[base[a[i]]].pop();
    }
    stk[base[a[i]]].push(a[i]);
  }
  cout<<n<<endl;
  return 0;
} 

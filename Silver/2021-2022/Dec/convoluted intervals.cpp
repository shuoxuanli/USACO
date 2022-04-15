#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 1e4+1;
ll l[maxN], r[maxN], prefix[maxN];

int main() {
  int n, m;
  cin>>n>>m;

  for(int i = 0; i < n; i++) {
    int a, b;
    cin>>a>>b;
    l[a]++;
    r[b]++;
  }

  for(int i = 0; i <= m; i++) {
    for(int j = 0; j <= m; j++) {
      prefix[i+j] += l[i]*l[j];
      prefix[i+j+1] -= r[i]*r[j];
    }
  }

  for(int i = 0; i <= 2*m; i++) {
    if(i) prefix[i] += prefix[i-1];
    cout<<prefix[i]<<endl;
  }
} 

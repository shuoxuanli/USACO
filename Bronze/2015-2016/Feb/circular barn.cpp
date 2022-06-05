#include<bits/stdc++.h>
using namespace std;

int cows[1001];

int main() {
  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>cows[i];
  }

  int ans = INT_MAX;
  for(int i = 0; i < n; i++) {
    int count = 0;
    int distance = 0;
    for(int j = i+1; j < n + i; j++) {
      count++;
      distance += cows[j%n]*count;
    }
    ans = min(distance, ans);
  }
  cout<<ans<<endl;
  return 0;
} 

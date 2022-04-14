#include <bits/stdc++.h>
using namespace std;

int diamonds[1001];

int main() {

  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  int n, k;
  cin>>n>>k;

  for(int i = 0; i < n; i++) {
    cin>>diamonds[i];
  }

  sort(diamonds, diamonds + n);

  int ans = 0;
  for(int j = 0; j < n; j++) {
    int temp = 1;
    for(int i = j+1; i < n; i++) {
      if(diamonds[i] - diamonds[j] <= k) {
        temp++;
      } else {
        break;
      }
    }
    ans = max(temp, ans);
  }

  cout<<ans<<endl;
  return 0;
} 

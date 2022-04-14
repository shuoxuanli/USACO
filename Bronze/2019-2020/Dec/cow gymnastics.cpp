#include<bits/stdc++.h>
using namespace std;

int rk[11][21], pairs[6000][2], cnt[6000];

int main() {
  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);

  int k, n;
  cin>>k>>n;

  int sum = 0;

  for(int i = 0; i < k; i++) {
    for(int j = 0; j < n; j++) {
      if(i == 0) {
        sum+=j;
      }
      cin>>rk[i][j];
    }
  }

  int count = 0;
  int max;
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < n; j++) {
      for(int m = j+1; m < n; m++) {
        pairs[count][0] = rk[i][j];
        pairs[count][1] = rk[i][m];
        count++;
      }
    }
  }

  for(int i = 0; i < count; i++) {
    for(int j = i+1; j < count; j++) {
      if(pairs[i][0] == pairs[j][0] && pairs[i][1] == pairs[j][1]) {
        cnt[i]++;
      }
    }
  }

  int ans = 0;

  for(int i = 0; i < sum; i++) {
    if(cnt[i] == k-1) ans++;
  }

  cout<<ans<<endl;
  return 0;
} 

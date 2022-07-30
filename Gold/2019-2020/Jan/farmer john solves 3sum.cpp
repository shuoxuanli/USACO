#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int OFFSET = 1e6;
int n, q, a[5001], cnt[2000001];
ll dp[5001][5001];

int main() {
  freopen("threesum.in", "r", stdin);
  freopen("threesum.out", "w", stdout);
  
  cin>>n>>q;

  for(int i = 1; i <= n; i++) {
    cin>>a[i];
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cnt[a[j]+OFFSET] = 0;
    }
    for(int j = i+1; j <= n; j++) {
      int k = -a[i]-a[j];
      if(k >= -OFFSET && k <= OFFSET) {
        dp[i][j] = cnt[k+OFFSET];
      }
      cnt[a[j]+OFFSET]++;
    }
  }
  
  for(int i = n-1; i > 0; i--) {
    for(int j = i+1; j <= n; j++) {
      dp[i][j] += dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
    }
  }

  for(int i = 0; i < q; i++) {
    int a, b;
    cin>>a>>b;
    cout<<dp[a][b]<<endl;
  }
  return 0;
} 

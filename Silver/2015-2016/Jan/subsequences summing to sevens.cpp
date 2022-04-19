#include <bits/stdc++.h>
using namespace std;

long long prefix[50001];

int main() {
  freopen("div7.in", "r", stdin);
  freopen("div7.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 1; i <= n; i++) {
    long long seq;
    cin>>seq;
    prefix[i] = prefix[i-1] + seq;
  }

  int ans = 0;
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = i + cnt; j <= n; j++) {
      long long tmp = prefix[j] - prefix[i-1];
      if(tmp % 7 == 0) {
        ans = max(j-i+1, ans);
        cnt = ans - 1;
      }
    }
  }

  cout<<ans<<endl;
  return 0;
}

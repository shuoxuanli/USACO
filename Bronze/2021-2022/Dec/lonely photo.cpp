#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 +1;
string s;
int pre[N][2], nex[N][2];

int main() {
  int n;
  cin>>n;
  cin>>s;

  pre[1][0] = pre[1][1] = 0;
  for(int i = 1; i <= n; i++) {
    if(s[i-1] == 'G') {
      pre[i+1][0] = i;
      pre[i+1][1] = pre[i][1];
    } else {
      pre[i+1][1] = i;
      pre[i+1][0] = pre[i][0];
    }
  }

  nex[n][0] = nex[n][1] = n+1;
  for(int i = n; i >= 1; i--) {
    if(s[i-1] == 'G') {
      nex[i-1][0] = i;
      nex[i-1][1] = nex[i][1];
    } else {
      nex[i-1][1] = i;
      nex[i-1][0] = nex[i][0];
    }
  }

  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    if(s[i-1] == 'G') {
      ans += 1ll * (nex[i][0] - i) * (i- pre[i][0]);
    } else {
      ans += 1ll * (nex[i][1] - i) * (i- pre[i][1]);
    }
  }

  for(int i = 0; i < n-1; i++) {
    if(s[i] != s[i+1]) {
      ans -= 2;
    }
  }

  cout<<ans-n<<endl;
  return 0;
} 

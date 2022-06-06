#include <bits/stdc++.h>
using namespace std;

int pos[100001], speed[100001];

int main() {
  freopen("cowjog.in", "r", stdin);
  freopen("cowjog.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>pos[i]>>speed[i];
  }

  int ans = 1;
  int slow = speed[n-1];
  for(int i = n-2; i >= 0; i--) {
    if(speed[i] <= slow) {
      ans++;
    }
    slow = min(slow, speed[i]);
  } 

  cout<<ans<<endl;
  return 0;
} 

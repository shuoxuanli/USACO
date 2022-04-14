#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int n;
int a[N], b[N];
int paths[N+10], adj[N+10];

int main() {
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);

  cin>>n;
  for(int i = 0; i < n-1; i++) {
    cin>>a[i]>>b[i];
  }

  for(int i = 0; i < n-1; i++) {
    paths[a[i]]++;
    paths[b[i]]++;
    adj[a[i]] = b[i];
    adj[b[i]] = a[i];
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int temp = 0;
    temp += paths[i];
    if(paths[adj[i]] != 0) {
      temp++;
    }
    ans = max(ans, temp);
  }

  cout<<ans<<endl;
  return 0;
} 

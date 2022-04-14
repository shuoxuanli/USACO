#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("breedflip.in", "r", stdin);
  freopen("breedflip.out", "w", stdout);

  int n;
  cin>>n;

  string a, b;
  cin>>a;
  cin>>b;

  bool diff[1001];
  memset(diff, true, sizeof(diff));

  int ans = 0, cnt = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] != b[i]) {
      diff[i] = true;
    }
    else {diff[i] = false;}

    if(i > 0){
      if(diff[i] == false && diff[i-1] == true) {
      ans++;
      }
    }
  }
  cout<<ans<<endl;
} 

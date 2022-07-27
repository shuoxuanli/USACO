#include<bits/stdc++.h>
using namespace std;

long long cows[21], stalls[21], cnt[30];

int main() {
  int n;
  cin>>n;
  for(int i = 0; i < n; i++) {
    cin>>cows[i];
  }

  for(int i = 0; i < n; i++) {
    cin>>stalls[i];
  }

  sort(stalls, stalls+n);


  for(int i = 0; i < n; i++) {
    int count = 0;
    for(int j = 0; j < n; j++) {
      if(stalls[i] >= cows[j]) {
        count++;
      }
    }
    cnt[i] += count - i;
  }

  long long ans = 1;
  for(int i = 0; i < n; i++) { 
    ans *= cnt[i];
  }
  
  cout<<ans<<endl; 
  return 0;
} 

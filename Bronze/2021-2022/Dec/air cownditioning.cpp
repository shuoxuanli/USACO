#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int nums[N];

int main() {
  int n, t;
  cin>>n;
  
  for(int i = 1; i <= n; i++) {
    cin>>nums[i];
  }
  
  for(int i = 1; i <= n; i++) {
    cin>>t;
    nums[i] -= t;
  }

  long long ansa = 0, ansb = 0;

  for(int i = 1; i <= n; i++) {
    if(nums[i] > nums[i-1]) {
      ansa += abs(nums[i] - nums[i-1]);
    } else {
      ansb += abs(nums[i] - nums[i-1]);
    }
  }
  
  cout<<max(ansa, ansb)<<endl;
  return 0;
} 

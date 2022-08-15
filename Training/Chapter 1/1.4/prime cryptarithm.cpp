/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: crypt1
*/
#include<bits/stdc++.h>
using namespace std;

int n;
int nums[10];

bool multiplication(int i, int j, int k, int x, int y) {
  int top = i*100+j*10+k;
  int bottom = x*10 + y;
  int tmp1 = y*top;
  int tmp2 = x*top;

  int cnt = 0;
  while(tmp1 > 0) {
    bool found = false;
    int digit = tmp1%10;
    for(int i = 0; i < n; i++) {
      if(nums[i] == digit) {
        found = true;
        break;
      }
    }
    if(!found) {
      return false;
    }
    tmp1/=10;
    cnt++;
  }

  if(cnt != 3) return false;

  cnt = 0;
  while(tmp2 > 0) {
    bool found = false;
    int digit = tmp2%10;
    for(int i = 0; i < n; i++) {
      if(nums[i] == digit) {
        found = true;
        break;
      }
    }
    if(!found) {
      return false;
    }
    tmp2/=10;
    cnt++;
  }
  if(cnt != 3) return false;

  cnt = 0;
  int product = top*bottom;
  while(product > 0) {
    bool found = false;
    int digit = product % 10;
    for(int i = 0; i < n; i++) {
      if(nums[i] == digit) {
        found = true;
      }
    }
    if(!found) {
      return false;
    }
    product/=10;
    cnt++;
  }
  if(cnt != 4) return false;

  return true;
}

int main() {
  freopen("crypt1.in", "r", stdin);
  freopen("crypt1.out", "w", stdout);

 cin>>n;

 for(int i = 0; i < n; i++) {
   cin>>nums[i];
 }

 int ans = 0;
 for(int i = 0; i < n; i++) {
   for(int j = 0; j < n; j++) {
     for(int k = 0; k < n; k++) {
       for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
          if(multiplication(nums[i],nums[j],nums[k],nums[x],nums[y])) {
            ans++;
          }
        }
       }
     }
   }
 }

 cout<<ans<<endl;
 return 0;
} 

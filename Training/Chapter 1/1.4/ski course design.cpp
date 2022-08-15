/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: skidesign
*/
#include<bits/stdc++.h>
using namespace std;

int n;
int hills[1001];

int main() {
  freopen("skidesign.in", "r", stdin);
  freopen("skidesign.out", "w", stdout);

  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>hills[i];
  }

  int s = 0, t = 17;
  int ans = INT_MAX;
  for(int i = 0; i <= 83; i++) {
    int cost = 0;
    for(int j = 0; j < n; j++) {
      if(hills[j] < s) {
        cost += pow(s-hills[j], 2);
      }
      else if(hills[j] > t) {
        cost += pow(hills[j]-t, 2);
      }
    }
    ans = min(cost, ans);
    s++;
    t++;
  }

  cout<<ans<<endl;
  return 0;
} 

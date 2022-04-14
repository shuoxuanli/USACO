#include<bits/stdc++.h>
using namespace std;

int mp[2001][2001];
int mp2[2001][2001];

int p[10010];

int main() {

  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);

  int n;
  cin>>n;

  mp[1000][1000] = 1;
  bool found = false;
  int neg = 0;
  int ans = INT_MAX;
  int loc1 = 1000;
  int loc2 = 1000;
  int minimum = INT_MAX;
  int pre = 0;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    char d;
    int steps;
    cin>>d>>steps;
    
    for(int j = 0; j < steps; j++) {
      sum++;
      if(d == 'S') {
        loc1++;
      }
      else if(d == 'N') {
        loc1--;
      }
      else if(d == 'E') {   
        loc2++;
      }
      else if(d == 'W') {
        loc2--;
      }

      if(mp[loc1][loc2] >= 1) {
        found = true;
        minimum = sum - mp2[loc1][loc2];
      }

      mp[loc1][loc2]++;
      mp2[loc1][loc2] = sum;
      neg += mp[loc1][loc2];

      ans = min(ans, minimum);
    }
    
  }

  if(neg==sum) cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
} 

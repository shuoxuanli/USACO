#include<bits/stdc++.h>
using namespace std;

int cities[501][501], cost[501], m[501];

int main() {
  freopen("cowroute.in", "r", stdin);
  freopen("cowroute.out", "w", stdout);

  int n, a, b;
  cin>>a>>b>>n;

  for(int i = 0; i < n; i++) {
    cin>>cost[i]>>m[i];
    for(int j = 0; j < m[i]; j++) {
      cin>>cities[i][j];
    }
  }

  vector<pair<int, int>> v;
  for(int i = 0; i < n; i++) {
    bool start = false;
    for(int j = m[i]-1; j >= 0; j--) {
      if(start) {
        v.push_back(make_pair(cities[i][j], cost[i]));
      }

      if(cities[i][j] == b) {
        start = true;
      }
    }
  }

  int ans = INT_MAX;
  for(int i = 0; i < n; i++) { 
    bool start = false;
    for(int j = 0; j < m[i]; j++) {
      if(start) {
        for(int k = 0; k < v.size(); k++) {
          if(cities[i][j] == v[k].first) {
            ans = min(ans, cost[i] + v[k].second);
          }
        }
      }
      if(cities[i][j] == a) {
        start = true;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    int tmp1 = -1;
    int tmp2 = -1;
    for(int j = 0; j < m[i]; j++) {
      if(cities[i][j] == a) {
        tmp1 = j;
      }
      if(cities[i][j] == b) {
        tmp2 = j;
      }
    }
    if(tmp1<tmp2 && tmp1 != -1 && tmp2 != -1) {
      ans = min(ans, cost[i]);
    }
  }
  
  ans = (ans==INT_MAX) ? -1:ans;

  cout<<ans<<endl;
  return 0;
}

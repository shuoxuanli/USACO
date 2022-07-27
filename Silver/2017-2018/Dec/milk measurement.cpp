#include<bits/stdc++.h>
using namespace std;
 
struct measurement {
  int day;
  int cow;
  int delta;
};

int main() {
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);
 
  int n, g;
  cin>>n>>g;
  
  vector<measurement> a(n);
  for(int i = 0; i < n; i++) {
    cin>>a[i].day>>a[i].cow>>a[i].delta;
  }
  
  sort(a.begin(), a.end(), [] (const measurement &m1, const measurement &m2) {
    return m1.day<m2.day;
  });

  map<int, int, greater<int>> cnt;
  cnt[0] = n+1;
 
  int ans = 0;
  map<int, int> mk;
  for (measurement m : a) {
    int milk = mk[m.cow];
 
    bool wasTop = (milk == cnt.begin()->first);
    int wasRep = cnt[milk]; 

    if (wasRep == 1) {
      cnt.erase(milk);
    } else {
      cnt[milk]--;
    }
 
    milk += m.delta;
    mk[m.cow] = milk;
    cnt[milk]++;
    int isRep = cnt[milk];
    bool isTop = (milk == cnt.begin()->first);
    if (wasTop) {
      if (!isTop || wasRep != 1 || isRep != 1) {
        ans++;
      }
    } else if (isTop) {
      ans++;
    }
  }
  
  cout<<ans<<endl;
  return 0;
}

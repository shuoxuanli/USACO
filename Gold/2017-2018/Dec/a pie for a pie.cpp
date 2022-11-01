#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, d;
set<pair<int, int>> a[2];
int t[200001][2], dis[200001][2];

int main() {
  ifstream cin("piepie.in");
  ofstream cout("piepie.out");
  
  cin>>n>>d;
  for(int i = 1; i <= 2*n; i++) {
    cin>>t[i][0]>>t[i][1];
    if(i > n) a[0].insert({t[i][0], i});
    else a[1].insert({t[i][1], i});
  }
  
  queue<pair<int, int>> q;
  memset(dis, 0x3f, sizeof(dis));
  for(int i = 1; i <= 2*n; i++) {
    if(t[i][0] == 0 && i > n) {
      q.push({i, 0});
      dis[i][0] = 0;
    } else if(t[i][1] == 0 && i <= n) {
      q.push({i, 1});
      dis[i][1] = 0;
    }
  }
  
  while(!q.empty()) {
    int x, i;
    tie(x, i) = q.front(), q.pop();
  
    if(a[i].count({t[x][i], x})) {
      a[i].erase({t[x][i], x});
    }
  
    if(dis[x][i^1] > dis[x][i] + 1) {
      dis[x][i^1] = dis[x][i] + 1;
    }
  
    vector<pair<int, int>> e;
    auto it = a[i^1].lower_bound({t[x][i^1] - d, 0});
    while(it != a[i^1].end() && it->first <= t[x][i^1]) {
      e.push_back(*it);
      if(dis[it->second][i^1] > dis[x][i] + 1) {
        q.push({it->second, i^1});
        dis[it->second][i^1] = dis[x][i] + 1;
      }
      it++;
    }
    for(auto x : e) {
      a[i^1].erase(x);
    }
  }
  
  for(int i = 1; i <= n; i++) {
    cout<<(dis[i][0] == 0x3f3f3f3f ? -1 : dis[i][0])<<endl;
  }
  return 0;
}

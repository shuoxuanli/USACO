#include <bits/stdc++.h>
using namespace std;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
  if(a.first.second < b.first.second) return true;
  else if(a.first.second > b.first.second) return false;
  return a.first.first < b.first.first;
}

int main() {
  freopen("reduce.in", "r", stdin);
  freopen("reduce.out", "w", stdout);
	
  int n; cin >> n;
  vector<pair<pair<int, int>, int> > v(n);
  vector<pair<int, int> > p(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].first.first >> v[i].first.second;
    v[i].second = i;
    p[i] = v[i].first;
  }

  int mn = INT_MAX;
  vector<int> x, y;
  sort(v.begin(), v.end());
  for(auto& i: v) x.emplace_back(i.second);
  sort(v.begin(), v.end(), comp);
  for(auto& i: v) y.emplace_back(i.second);
	
  for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) for(int k = 0; k < 4; k++) for(int l = 0; l < 4; l++){
    if(i+j>3 || k+l>3) continue;
    int mnx = p[x[i]].first, mxx = p[x[n-1-j]].first, mny = p[y[k]].second, mxy = p[y[n-1-l]].second;
    int cnt = 0;
    for(int m = 0; m < n; m++){
      if(p[m].first>=mnx && p[m].first<=mxx && p[m].second>=mny && p[m].second<=mxy) continue;
        cnt++;
      }
      if(cnt<=3){
        mn = min(mn, (mxy-mny)*(mxx-mnx));
      }
    }
  cout << mn << "\n";
}

#include <bits/stdc++.h>
using namespace std;

struct view{
  int x, y, org;
};

view mountain[100001];

bool cmp(const view&a, const view&b) {
  return a.x < b.x;
}

int main() {
  ifstream cin("mountains.in");
  ofstream cout("mountains.out");

  int n;
  cin>>n;


  for(int i = 0; i < n; i++) {
    cin>>mountain[i].x>>mountain[i].y;
    mountain[i].org = i;
  }

  sort(mountain, mountain+n, cmp);

  int r = mountain[0].x + mountain[0].y, idx = 0;
  map<int, int> ans; 
  for(int i = 0; i < n; i++) {
    if(i == idx) {
      ans[mountain[i].org]++;
    }
    else if(mountain[i].x > r) {
      ans[mountain[i].org]++;
    }
    else if(mountain[i].x <= r && mountain[i].y > abs(mountain[idx].x + mountain[idx].y - mountain[i].x)) {
      ans[mountain[i].org]++;
    }
    if(mountain[i].x + mountain[i].y > r) {
      r = mountain[i].x + mountain[i].y;
      idx = i;
    }
  } 

  
  int l = mountain[n-1].x - mountain[n-1].y;
  idx = n-1;
  for(int i = n-1; i >= 0; i--) {
    if(i == idx) {
      ans[mountain[i].org]++;
    }
    else if(mountain[i].x < l) {
      ans[mountain[i].org]++;
    }
    else if(mountain[i].x >= l && mountain[i].y > abs(mountain[i].x - (mountain[idx].x - mountain[idx].y))) {
      ans[mountain[i].org]++;
    }
    if(mountain[i].x - mountain[i].y < l) {
      l = mountain[i].x - mountain[i].y;
      idx = i;
    }
  }

  int cnt = 0;
  for(auto x : ans){
    if(x.second==2) cnt++;
  }
  cout<<cnt<<endl;
  return 0;
} 

#include<bits/stdc++.h>
using namespace std;

struct cow {
  int pos;
  bool sick;
};

bool cmp(cow a, cow b) {
  return a.pos < b.pos;
}
cow line[1001];

int main() {

  freopen("socdist2.in", "r", stdin);
  freopen("socdist2.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>line[i].pos>>line[i].sick;
  }

  sort(line, line + n, cmp);

  int r = INT_MAX;
  int diff = 0;
  for(int i = 0; i < n-1; i++) {
    if(line[i].sick != line[i+1].sick) {
      r = min(line[i+1].pos - line[i].pos - 1, r);
    }
    diff = max(line[i+1].pos - line[i].pos, diff);
  }

  if(r == INT_MAX) {
    r = diff;
  }

  int ans = 1;
  for(int i = 0; i < n-1; i++) {
    if(line[i].sick && line[i+1].sick && line[i].pos + r < line[i+1].pos) {
      ans++;
    }
    else if(!line[i].sick && line[i+1].sick) {
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
} 

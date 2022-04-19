#include<bits/stdc++.h>
using namespace std;

struct cows {
  int locs, dur;
};

cows c[101];

bool cmp (cows a, cows b){
  return a.locs < b.locs;
}

int main() {
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>c[i].locs>>c[i].dur;
  }

  sort(c, c+n, cmp);

  int curr = 0;
  int count = 0;
  for(int i = 0; i < n; i++) {
    if(c[i].locs + c[i].dur > c[i+1].locs) {
      count++;
    }

    if(count == 1) {  
      curr = c[i].locs + c[i].dur;
      continue;
    }
    
    curr += c[i].dur;

    if(curr < c[i+1].locs) {
      curr = c[i+1].locs;
    }
  }

  cout<<curr<<endl;
  return 0;
} 

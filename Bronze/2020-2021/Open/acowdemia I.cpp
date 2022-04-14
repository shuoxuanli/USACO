#include<bits/stdc++.h>
using namespace std;

int cit[100001];

int hIndex(int n) {
  int bm = 1;
  int count = 0;
  int hIndex = 0;
  for(int i = 0; i < n; i++) {
    if(cit[i] >= bm) {
      count++;
    }
    if(count == bm) {
      hIndex = bm;
      bm++;
    }
  }
  return hIndex;
}

bool cmp(int a, int b) {
  return a > b;
}

int main() {
  int n, l;
  cin>>n>>l;

  for(int i = 0; i < n; i++) {
    cin>>cit[i];
  }

  sort(cit, cit+n, cmp);

  int h = hIndex(n);
  int ans = h;
  int cnt = 0;
  for(int i = 0; i < h+1; i++) {
    if(l <= 0) {
      break;
    }
    if(cit[i] >= h) {
      cnt++;
    }
    if(cit[i] == h) {
      l--;
    }
  }

  if(cnt == h+1) {
    ans++;
  }

  cout<<ans<<endl;
  return 0;
}   

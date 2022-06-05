#include<bits/stdc++.h>
using namespace std;

int hb[101];

int blast(int start, int length, bool left) {
  int src = start, dis = 1, dir = left ? -1 : 1;
  
  while(src >= 0 && src < length) {
    int nxt = src;
    while(nxt + dir >= 0 && nxt + dir < length && abs(hb[src] - hb[nxt+dir]) <= dis) {
      nxt += dir;
    }
    if(src == nxt) {
      break;
    }

    src = nxt;
    dis++;
  }
  return src;
}

int main() {
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>hb[i];
  }

  sort(hb, hb+n);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    int left = blast(i, n, true);
    int right = blast(i, n, false);
    int temp = right - left + 1;
    ans = max(temp, ans);
  }

  cout<<ans<<endl;
  return 0;
} 

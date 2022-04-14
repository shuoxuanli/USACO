#include <bits/stdc++.h>
using namespace std;

struct interval {
  int a, b;
};

interval cows[20001];
int t[20001];
bool used[20001];

bool cmp(interval a, interval b) {
  return a.a < b.a;
}

int main() {
  freopen("helpcross.in", "r", stdin);
  freopen("helpcross.out", "w", stdout);
  int c, n;
  cin>>c>>n;

  for(int i = 0; i < c; i++) {
    cin>>t[i];
  }

  for(int i = 0; i < n; i++) {
    cin>>cows[i].a>>cows[i].b;
  }

  sort(t, t+c);
  sort(cows, cows + n, cmp);

  int ans = 0;
  for(int i = 0; i < c; i++) {
    int r = 0, tmp = INT_MAX, idx = 0;
    bool found = false;
    while(cows[r].a <= t[i] && r < n) {
      if(used[r] || cows[r].b < t[i]) {
        r++;
        continue;
      }
      found = true;
      if(cows[r].b < tmp) {
        tmp = cows[r].b;
        idx = r;
      }
      r++;
    }
    if(found) {
      ans++;
      used[idx] = true;
    }
  }

  cout<<ans<<endl;
  return 0;
} 

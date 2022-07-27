#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct pt {
  ll x, y;
};

struct node {
  ll x, y;
  int t;
};

pt lef[21], rig[21];
ll ans[41];

int main() {
  int n;
  cin>>n;

  ll tarx, tary;
  cin>>tarx>>tary;

  int cnt = 0, tmp = 0;
  for(int i = 0; i < n; i++) {
    ll r, c; 
    cin>>r>>c;
    if(cnt < n/2) {
      lef[cnt] = {r,c};
    } else {
      rig[tmp++] = {r,c};
    }
    cnt++;
  }

  int a = n/2, b = n-n/2;
  
  vector<node> l(1<<a), r(1<<b);
  
  for(int i = 0; i < a; i++) {
    for(int j = 1<<i; j < 2<<i; j++) {
      l[j].x = l[j-(1<<i)].x + lef[i].x;
      l[j].y = l[j-(1<<i)].y + lef[i].y;
      l[j].t = l[j-(1<<i)].t + 1;
    }
  }

  for(int i = 0; i < b; i++) {
    for(int j = 1<<i; j < 2<<i; j++) {
      r[j].x = r[j-(1<<i)].x + rig[i].x;
      r[j].y = r[j-(1<<i)].y + rig[i].y;
      r[j].t = r[j-(1<<i)].t + 1;
    }
  }
  
  for(int i = 0; i < 1<<b; i++) {
    r[i].x = tarx - r[i].x;
    r[i].y = tary - r[i].y;
  }


  sort(l.begin(), l.end(), [] (const node &a, const node &b) {
    if(a.x != b.x) {
      return a.x < b.x;
    }
    else if(a.y != b.y) {
      return a.y < b.y;
    } else {
      return a.t < b.t;
    }
  });
  
  sort(r.begin(), r.end(), [] (const node &a, const node &b) {
    if(a.x != b.x) {
      return a.x < b.x;
    }
    else if(a.y != b.y) {
      return a.y < b.y;
    } else {
      return a.t < b.t;
    }
  });
  
  int i = 0, j = 0;
  while(i < l.size() && j < r.size()) {
    if(l[i].x < r[j].x || (l[i].x == r[j].x && l[i].y < r[j].y)) {
      i++;
    }
    else if(l[i].x > r[j].x || (l[i].x == r[j].x && l[i].y > r[j].y)) {
      j++;
    } else {
      int ti = i, tj = j;
      vector<ll> di(21), dj(21);
      di[l[ti].t]++; dj[r[tj].t]++;
      int tmp = ti + 1;
      while(tmp < l.size() && l[ti].x == l[tmp].x && l[ti].y == l[tmp].y 
        && l[ti].x == r[tj].x && l[ti].y == r[tj].y) {
        di[l[tmp].t]++;
        tmp++;
      }
      i = tmp;
      tmp = tj + 1;
      while(tmp < r.size() && r[tj].x == r[tmp].x && r[tj].y == r[tmp].y 
        && l[ti].x == r[tj].x && l[ti].y == r[tj].y) {
        dj[r[tmp].t]++;
        tmp++;
      }
      j = tmp;

      for(int i = 0; i <= 20; i++) {
        for(int j = 0; j <= 20; j++) {
          ans[i+j] += di[i]*dj[j];
        }
      }
    }
  } 

  for(int i = 1; i <= n; i++) {
    cout<<ans[i]<<endl;
  }
  return 0;
}

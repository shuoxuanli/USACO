#include <bits/stdc++.h>
using namespace std;

struct cow{
  int w, x, d;
};

int n, m, sw = 0;
cow v[50001];

bool cmp(cow a, cow b) {
  return a.x < b.x;
}

bool check(int y) {
  int l = 0, r = 0;
  for(int i = 0; i < n; i++) {
    if(v[i].x <= y && v[i].d == -1) {
      l++;
    } 
    else if(v[i].x > y) {
      break;
    }
  }

  for(int i = n - 1; i >= 0; i--) {
    if(m-v[i].x <= y && v[i].d == 1) {
      r++;
    } 
    else if(m-v[i].x > y) {
      break;
    }
  }

  int sum = 0, i = 0;
  while(l > 0 && i < n) {
    sum += v[i].w;
    i++;
    l--;
  }

  i = n-1;
  while(r > 0 && i > 0) {
    sum += v[i].w;
    i--;
    r--;
  }

  return sum*2 >= sw;
}

int main() {
  ifstream cin("meetings.in");
  ofstream cout("meetings.out");

  cin>>n>>m;

  for(int i = 0; i < n; i++) {
    cin>>v[i].w>>v[i].x>>v[i].d;
    sw += v[i].w;
  }

  sort(v, v+n, cmp);

  int l = 0, r = m, t = 0;
  while(l <= r) {
    int mid = (l+r)/2;
    if(check(mid)) {
      t = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  queue<int> q;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(v[i].d == -1) {
      while(!q.empty() && q.front() + 2*t < v[i].x) {
        q.pop();
      }
      ans += q.size();
    } else {
      q.push(v[i].x);
    }
  }

  cout<<ans<<endl;
  return 0;
} 

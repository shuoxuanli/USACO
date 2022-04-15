#include <bits/stdc++.h>
using namespace std;

struct interval {
  long long start, end;
};

const int maxN = 1e5 + 1;
long long n, m;
interval line[maxN];

bool cmp (interval a, interval b) {
  return a.start < b.start;
}

bool check (long long dis) {
  long long cnt = 0;
  long long prev = INT_MIN;
  for(long long i = 0; i < m; i++) {
    while(max(prev + dis, line[i].start) <= line[i].end) {
      prev = max(prev + dis, line[i].start);
      cnt++;
      if(cnt >= n) {
        break;
      }
    }
    if(cnt >= n) {
      break;
    }
  }
  return cnt >= n;
}

int main() {
  freopen("socdist.in", "r", stdin);
  freopen("socdist.out", "w", stdout);

  cin>>n>>m;
  
  for(long long i = 0; i < m; i++) {
    cin>>line[i].start>>line[i].end;
  }

  sort(line, line+m, cmp);

  long long ans = 0;
  long long l = 1, r = line[m-1].end - line[0].start;
  while(l <= r) {
    long long mid = (l+r)/(long long)(2);
    if(check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout<<ans<<endl;
  return 0;
} 

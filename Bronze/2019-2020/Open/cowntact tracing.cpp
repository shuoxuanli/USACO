#include <bits/stdc++.h>
using namespace std;

struct handshake {
  int t, x, y;
};

handshake hs[251];
int states [101];
int n,t; 
bool candidates[101];
int minK = INT_MAX, maxK = INT_MIN;
string s;

bool cmp(handshake a, handshake b) {
  return a.t < b.t;
}

void sh(int k) {
  for(int i = 0; i < t; i++) {
    int x = hs[i].x;
    int y = hs[i].y;
    if(states[x] > 0 && states[y] > 0) {
      states[x]--;
      states[y]--;
    }
    else if(states[x] > 0) {
      states[x]--;
      if(states[y] == -1) {
        states[y] = k;
      }
    }
    else if(states[y] > 0) {
      states[y]--;
      if(states[x] == -1) {
        states[x] = k;
      }
    }
  }
}

int main() {
  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);

  cin>>n>>t;

  cin>>s;

  for(int i = 0; i < t; i++) {
    cin>>hs[i].t>>hs[i].x>>hs[i].y;
  }

  sort(hs, hs+t, cmp);

  for(int n0 = 1; n0 <=n; n0++) {
    if(s[n0-1] == '0') {
      continue;
    }

    for(int k = 0; k <= t; k++) {
      memset(states, -1, sizeof(states));
      states[n0] = k;

      sh(k);

      bool match = true;
      for(int i = 0; i < n; i++) {
       char c = '0';
        if(states[i+1] != -1) {
         c = '1';
        }
        if(s[i] != c) {
         match = false;
         break;
        }
      }


      if(match) {
        candidates[n0] = true;
        minK = min(minK, k);
        maxK = max(maxK, k);
      }
    }
  }

  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(candidates[i]) {
      cnt++;
    }
  }

  cout<<cnt<<" "<<minK<<" ";

  if(maxK == t) {
    cout<<"Infinity"<<endl;
  } else {
    cout<<maxK<<endl;
  }
}

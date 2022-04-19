#include<bits/stdc++.h>
using namespace std;

struct cow {
  int day, milk;
  string name;
};

cow rec[101];
int mk[3], display[3] = {1,1,1};

bool cmp(cow a, cow b) {
  return a.day < b.day;
}

int main() {
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);

  int n;
  cin>>n;
  
  for(int i = 0; i < n; i++) {
    mk[i]= 7;
  }

  for(int i = 0; i < n; i++) {
    cin>>rec[i].day>>rec[i].name>>rec[i].milk;
  }

  sort(rec, rec+n, cmp);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(rec[i].name == "Bessie") {
      mk[0] += rec[i].milk;
    }
    else if(rec[i].name == "Elsie") {
      mk[1] += rec[i].milk;
    }
    else if(rec[i].name == "Mildred") {
      mk[2] += rec[i].milk;
    }

    int mxn = 0;
    for(int j = 0; j < 3; j++) {
      mxn = max(mxn, mk[j]);
    }

    int count = 0;
    for(int j = 0; j < 3; j++) {
      if(mk[j] == mxn) {
        if(display[j] != 1) {
          count++;
          display[j] = 1;
        }
      }
      else {
        if(display[j] == 1) {
          count++;
          display[j] = 0;
        }
      }
    }

    if(count!=0) {
      ans++;
    }
  }
  cout<<ans<<endl;
}

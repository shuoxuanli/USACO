/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: barn1
*/
#include<bits/stdc++.h>
using namespace std;

struct barn{
  int pos, diff;
};

int m, s, c;
int rec[51];
barn cows[210], org[210];

bool cmp(barn a, barn b) {
  return a.diff > b.diff;
}

bool cmp2(barn a, barn b) {
  return a.pos < b.pos;
}

int getIndex(int pos) {
  for(int i = 0; i < c; i++) {
    if(org[i].pos == pos) {
      return i;
    }
  }
  return 0;
}

int main() {
  freopen("barn1.in", "r", stdin);
  freopen("barn1.out", "w", stdout);

  cin>>m>>s>>c;
  
  for(int i = 0; i < c; i++) {
    cin>>cows[i].pos;
    org[i].pos = cows[i].pos;
  }

  sort(org, org+c, cmp2);
  sort(cows, cows+c, cmp2);
  

  int start = org[0].pos;
  int end = org[c-1].pos;

  if(m == 1) {
    cout<<end-start+1<<endl;
    return 0;
  }
  else if (m > c) {
    cout<<c<<endl;
    return 0;
  }

  for(int i = 0; i < c; i++) {
    if(i==0) {
      cows[i].diff = 0;
    } else {
      cows[i].diff = cows[i].pos - cows[i-1].pos;
    }
  }

  sort(cows, cows+c, cmp);

  for(int i = 0; i < m-1; i++) {
    rec[i] = org[getIndex(cows[i].pos)-1].pos;
  }
  
  sort(rec, rec+m-1);

  int ans = 0;
  int pre = start;
  for(int i = 0; i < m-1; i++) {
    ans += rec[i] - pre + 1;
    pre = org[getIndex(rec[i]) + 1].pos;
  }
  
  ans += end - pre + 1;

  cout<<ans<<endl;
  return 0;
} 

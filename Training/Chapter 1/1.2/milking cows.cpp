/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: milk2
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int timeline[N];

int main() {
  freopen("milk2.in", "r", stdin);
  freopen("milk2.out", "w", stdout);

  int n;
  cin>>n;

  int mi = INT_MAX, ma = INT_MIN;
  for(int i = 0; i < n; i++) {
    int start, end;
    cin>>start>>end;
    mi = min(start, mi);
    ma = max(end, ma);
    for(int j = start; j < end; j++) {
      timeline[j]++;
    }
  }

  int milk = 0, nomilk = 0;
  int temp1 = 0, temp2 = 0;
  for(int i = mi; i <= ma; i++) {
    if(timeline[i] >= 1 && timeline[i-1]== 0) {
      nomilk = max(temp2, nomilk);
      temp2 = 0;
    }
    else if(timeline[i] == 0 && timeline[i-1] >= 1) {
      milk = max(temp1, milk);
      temp1 = 0;
    }

    if(timeline[i] >= 1) {
      temp1++;
    }
    if(timeline[i] == 0) {
      temp2++;
    }
  }

  cout<<milk<<" "<<nomilk<<endl;
  return 0;
} 

#include<bits/stdc++.h>
using namespace std;

int logs[101], breakout[101];

int main() {

  freopen("taming.in", "r", stdin);
  freopen("taming.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>logs[i];
  }

  for(int i = 0; i < n; i++) {
    if(logs[i] == -1) {
      breakout[i] = -1;
      continue;
    }
    else if(logs[i] != -1 && i-logs[i] < 0) {
      cout<<-1<<endl;
      return 0;
    }
    else if (logs[i] != 0 && logs[i] != -1){
      int count = 0;
      for(int j = i; j>= i - logs[i]; j--) {
        if(logs[j] != -1 && logs[j] != logs[i]- count) {
          cout<<-1<<endl;
          return 0;
        } else {
          breakout[j] = logs[i] - count;
          count++;
        }
      }
    }
  }

  breakout[0] = 0;

  int mi = 0;
  int mx= 0;
  for(int i = 0; i < n; i++) {
    if(breakout[i] == 0) {
      mx++;
      mi++;
    }
    else if(breakout[i] == -1) {
      mx++;
    }
  }

  cout<<mi<<" "<<mx<<endl;
  return 0;
} 

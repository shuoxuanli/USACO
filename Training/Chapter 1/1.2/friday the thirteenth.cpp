/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: friday
*/
#include <bits/stdc++.h>
using namespace std;

int freqs[8];

int main() {
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);

  int n;
  cin>>n;
  int pre = 0; 
  for(int i = 1900; i < 1900 + n; i++) {
    for(int j = 1; j <= 12; j++) {
      int days = 0;
      if(j==9||j==4||j==6||j==11) {
        days = 30;
      } 
      else if(j==2) {
        if(i % 400 == 0) {
          days = 29;
        }
        else if(i % 100 != 0 && i % 4 == 0) {
          days = 29;
        } else {
          days = 28;
        }
      }
      else {
        days = 31;
      }

      for(int k = 1; k <= days; k++) {
        pre++;
        if(pre > 7) {
          pre %= 7;
        }
        if(k == 13) {
          freqs[pre]++;
        } 
      }
      if(i == 0 && j == 1) {
        cout<<freqs[6]<<endl;
      }
    }
  }

  cout<<freqs[6]<<" "<<freqs[7]<<" ";
  for(int i = 1; i <= 5; i++) {
    if(i == 5) {
      cout<<freqs[i]<<endl;
    } else {
      cout<<freqs[i]<<" ";
    }
  }
  return 0;
} 

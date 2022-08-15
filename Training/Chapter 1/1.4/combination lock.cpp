/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: combo
*/
#include<bits/stdc++.h>
using namespace std;

int n;
int master[3], fj[3], mpos[3][5], fjpos[3][5];

int main() {
  freopen("combo.in", "r", stdin);
  freopen("combo.out", "w", stdout);

  cin>>n;

  for(int i = 0; i < 3; i++) {
    cin>>fj[i];
  }

  for(int i = 0; i < 3; i++) {
    cin>>master[i];
  }

  set<int> s;
  
  for(int i = 0; i < 3; i++) {
    int cnt = 0;
    int count = 0;
    for(int j = master[i]-2; j <= master[i]+2; j++) {
      int temp = j;
      if(temp == master[i]) {
        cnt = 0;
      }
      if(temp <= 0) {
        temp = n-1+cnt;
      }
      else if(temp > n) {
        temp = cnt;
      }
      
      if(n==1) {
        temp = n;
      }

      mpos[i][count] = temp;
      cnt++;
      count++;
    }
  }

  for(int i = 0; i < 3; i++) {
    int cnt = 0;
    int count = 0;
    for(int j = fj[i]-2; j <= fj[i]+2; j++) {
      int temp = j;
      if(temp == fj[i]) {
        cnt = 0;
      }
      if(temp <= 0) {
        temp = n-1+cnt;
      }
      else if(temp > n) {
        temp = cnt;
      }

      if(n==1) {
        temp = n;
      }
      
      fjpos[i][count] = temp;
      cnt++;
      count++;
    }
  }

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      for(int k = 0; k < 5; k++) {
        s.insert(mpos[0][i]*100 + mpos[1][j]*10 + mpos[2][k]);
      }
    }
  }

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      for(int k = 0; k < 5; k++) {
        s.insert(fjpos[0][i]*100 + fjpos[1][j]*10 + fjpos[2][k]);
      }
    }
  }

  cout<<s.size()<<endl;
  return 0;
} 

#include <bits/stdc++.h>
using namespace std;

int win(int d1[4], int d2[4]) {
  int win = 0;
  for(int j = 0; j < 4; j++) {
    for(int k = 0; k < 4; k++) {
      if(d1[j] > d2[k]) {
        win++;
      }
    }
  }
  return win;
}

int main() {
  int t;
  cin>>t;

  for(int i = 0; i < t; i++) {
    int d1[4], d2[4];
    for(int j = 0; j < 4; j++) {
      cin>>d1[j];
    }
    for(int j = 0; j < 4; j++) {
      cin>>d2[j];
    }

    int win1 = 0, win2 = 0;
    for(int j = 0; j < 4; j++) {
      for(int k = 0; k < 4; k++) {
        if(d1[j] > d2[k]) {
          win1++;
        }
        else if(d1[j] < d2[k]) {
          win2++;
        }
      }
    } 
    
    bool pos = false;;
    if(win1 < win2) {
      for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++){
          for(int k = 1; k <= 10; k++){
            for(int l = 1; l <= 10; l++){
              int arr[4] = {i,j,k,l};
              int tmp1 = win(arr, d1);
              int tmp2 = win(d1, arr);
              int tmp3 = win(arr, d2);
              int tmp4 = win(d2, arr);
              if(tmp2 > tmp1 && tmp4 < tmp3) {
                pos = true;
              }
            }
          }
        }
      }
    }
    else if(win1 > win2) {
      for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++){
          for(int k = 1; k <= 10; k++){
            for(int l = 1; l <= 10; l++){
              int arr[4] = {i,j,k,l};
              int tmp1 = win(arr, d1);
              int tmp2 = win(d1, arr);
              int tmp3 = win(arr, d2);
              int tmp4 = win(d2, arr);
              if(tmp2 < tmp1 && tmp4 > tmp3) {
                pos = true;
              }
            }
          }
        }
      }
    } 

    string ans = pos ? "yes":"no";
    cout<<ans<<endl;
  }
  return 0;
}

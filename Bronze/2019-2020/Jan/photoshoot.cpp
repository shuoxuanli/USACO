#include<bits/stdc++.h>
using namespace std;

int b[1001], a[1001];

int main() {
  freopen("photo.in", "r", stdin);
  freopen("photo.out", "w", stdout);
  
  int n;
  cin>>n;

  for(int i = 0; i < n-1; i++) {
    cin>>b[i];
  }

  for(int i = 1; i < b[0]; i++) {
    bool error = false;
    int pre = i; 
    a[0] = i;
    for(int j = 0; j < n-1; j++) {
      int temp = b[j] - pre;
      if(temp <= 0) {
        error = true;
      }
      for(int k = 0; k <= j; k++) {
        if(a[k] == temp) {
          error = true;
          break;
        }
      }
    
      if(error) {
        memset(a, 0, sizeof(a));
        break;
      } else {
        a[j+1] = temp;
        pre = temp;
      }
    }
  
    if(error == false) {
      break;
    }
  }
  
  for(int i = 0; i < n; i++) {
    if(i != n-1) {
      cout<<a[i]<<" ";
    } else {
      cout<<a[i];
    }
  }

  return 0;
} 

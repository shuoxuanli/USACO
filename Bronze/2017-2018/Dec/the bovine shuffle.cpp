#include<bits/stdc++.h>
using namespace std;

int moveTo[101], finalOrder[101];

int main() {

  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);

  int n;

  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>moveTo[i+1];
  }
  for(int i = 0; i < n; i++) {
    cin>>finalOrder[i+1];
  }


  for(int i = 1; i <= n; i++) {
    int current = i;
    for(int j = 0; j < 3; j++) {
      current = moveTo[current];
    }
    cout<<finalOrder[current]<<endl;
  }

  return 0;
} 

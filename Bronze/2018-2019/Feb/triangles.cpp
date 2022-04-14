#include<bits/stdc++.h>
using namespace std;

int x[101], y[101];

int main() {
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  
  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>x[i]>>y[i];
  }

  int result = 0;
  for(int i = 0; i < n; i++) {
    int maxX = 0, maxY = 0;
    for(int j = 0; j < n; j++) {
      if(i == j) {
        continue;
      }
      if(x[i] == x[j]) {
        maxY = max(maxY, abs(y[i]-y[j]));
      }
      if(y[i] == y[j]) {
        maxX = max(maxX, abs(x[i]-x[j]));
      }
    }
    result = max(result, maxX*maxY);
  }
  cout<<result<<endl;
  return 0;
} 

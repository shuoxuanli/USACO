#include <bits/stdc++.h>
using namespace std;

int a[7];

int main() {
  for(int i = 0; i < 7; i++) {
    cin>>a[i];
  }

  sort(a, a+7);

  cout<<a[0]<<" "<<a[1]<<" "<<a[6]-a[0]-a[1]<<endl;
} 

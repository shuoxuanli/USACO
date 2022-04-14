#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout); 

  int a, b, c;
  cin>>a>>b>>c;

  int diff1 = b-a;
  int diff2 = c-b;

  int max = 0;
  int min = 0;
  if(diff1 > diff2) {
    max = diff1-1;
  } else {
    max = diff2-1;
  }

  if(diff1 == 1 && diff2 == 1) {
    min = 0;
  }
  else if(diff1 == 2 || diff2 == 2) {
    min = 1;
  } else {
    min = 2;
  }

  cout<<min<<endl;
  cout<<max<<endl;
} 

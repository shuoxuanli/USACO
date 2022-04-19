#include<bits/stdc++.h>
using namespace std;

int input[4][2];

int main() {
  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 2; j++) {
      cin>>input[i][j];
    }
  }

  int gp = input[3][1] - input[3][0];
  int sg = input[2][1] + gp - input[2][0];
  int bs = input[1][1] + sg - input[1][0];

  cout<<bs<<endl;
  cout<<sg<<endl;
  cout<<gp<<endl;
  return 0;
} 

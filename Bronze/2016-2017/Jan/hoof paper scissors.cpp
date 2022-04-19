#include<bits/stdc++.h>
using namespace std;

bool winner(int f, int s) {
  if(f==3 && s==2){
    return true;
  }
  if(f==2 && s==1){
    return true;
  }
  if(f==1 && s==3){
    return true;
  }
  else {return false;}
}

int game[101][2];

int main() {
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  
  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>game[i][0]>>game[i][1];
  }
  
  int cases[6][3] = {{1,2,3}, {1,3,2}, {2,1,3}, {2,3,1},{3,2,1},{3,1,2}};

  int ans = 0;
  for(int i = 0; i < 6; i++) {
    int count = 0;
   for(int j = 0; j < n; j++) {
     int rps1 = 0;
     int rps2 = 0;
     for(int k = 0; k < 3; k++) {
       if(game[j][0] == cases[i][k]) {
         rps1 = k+1;
       }
       if(game[j][1] == cases[i][k]) {
         rps2 = k+1;
       }
     }
     if(winner(rps1, rps2)) {count++;}
   }
   ans = max(ans, count);
  }

  cout<<ans<<endl;
  return 0;
} 

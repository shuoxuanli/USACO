/*
 ID: shuoxua2
 PROG: holstein
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int v, g, vit[25], tmp[25], soc[25][25];
vector<int> a;

int main() {
  ifstream cin("holstein.in");
  ofstream cout("holstein.out");
  
  cin>>v;
  
  for(int i = 1; i <= v; i++) {
    cin>>vit[i];
  }

  cin>>g;
  
  for(int i = 1; i <= g; i++) {
    for(int j = 1; j <= v; j++) {
      cin>>soc[i][j];
    }
  }
  
  int ans = INT_MAX;
  for(int i = 1; i <= (1<<g); i++) {
    int t = 0;
    memcpy(tmp, vit, sizeof(tmp));
    vector<int> val;
    for(int j = 1; j <= g; j++) {
      if(i & (1<<(j-1))) {
        t++;
        val.push_back(j);
        for(int k = 1; k <= v; k++) {
          tmp[k] -= soc[j][k];
        }
      }
    }
    bool b = 1;
    for(int j = 1; j <= v; j++) {
      if(tmp[j] > 0) {
        b = 0;
        break;
      }
    }
    if(b && t < ans) {
      ans = t;
      a = val;
    }
  }
  
  cout<<ans<<" ";
  for(int i = 0; i < a.size()-1; i++) cout<<a[i]<<" ";
  cout<<a.back()<<endl;
  
  return 0;
} 

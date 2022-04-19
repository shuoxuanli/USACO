#include<bits/stdc++.h>
using namespace std;

string animals[101][101];
int sk[101];

int main() {
  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);

  int n;
  cin>>n;

  unordered_map <string, int> c;

  for(int i = 0; i < n; i++) {  
    string animal;
    int skills;
    cin>>animal>>skills;
    sk[i] = skills;
    for(int j = 0; j < skills; j++) {
      cin>>animals[i][j];
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      int count = 0;
      for(int k = 0; k < sk[i]; k++) {
        for(int l = 0; l < sk[j]; l++) {
          if(animals[i][k] == animals[j][l]) {
            count++;
          }
        }
      }
      ans = max(count, ans);
    }
  }

  cout<<ans+1<<endl;
  return 0;
} 

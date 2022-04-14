#include<bits/stdc++.h>
using namespace std;

array<vector<int>,110> fav;

int main() {
  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout); 

  int n, m;
  cin>>n>>m;
  for(int i = 0; i < m; i++) {
    int num1, num2;
    cin>>num1>>num2;
    fav[num1].push_back(num2);
    fav[num2].push_back(num1);
  }

  int grass[110];
  for(int i = 1; i <= n; i++) {
    grass[i] = 1;
  }

  for(int i = 1; i <= n; i++) {
    sort(fav[i].begin(), fav[i].end());
    for(int j = 0; j < fav[i].size(); j++) {
      if(grass[fav[i][j]] == grass[i] && i < fav[i][j]) {
        grass[fav[i][j]]++;
      }
      else if(grass[fav[i][j]] == grass[i] && i > fav[i][j]) {
        grass[i]++;
      }
    }
  }

  string temp = "";
  for(int i = 1; i <= n; i++) {
    temp += to_string(grass[i]);
  }

  cout<<temp<<endl;
  return 0;
} 

#include <bits/stdc++.h>
using namespace std;

char spot[101][101], plain[101][101];

int main() {
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  int n, m;
  cin>>n>>m;

  for(int i = 0; i < n; i++) {
    string str;
    cin>>str;
    for(int j = 0; j < m; j++) {
      spot[i][j] = str[j];
    }
  }

  for(int i = 0; i < n; i++) {
    string str;
    cin>>str;
    for(int j = 0; j < m; j++) {
      plain[i][j] = str[j];
    }
  }

  int ans = 0;
  vector <char> v1;
  vector <char> v2;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      v1.push_back(spot[j][i]);
      v2.push_back(plain[j][i]);
    }
    bool works = true;
    for(int k = 0; k < v1.size(); k++) {
      for(int l = 0; l < v2.size(); l++) {
        if(v1[k] == v2[l]) {
          works = false;
          break;
        }
      }
      if(!works) {
         break;
      }
    }
    if(works) {
      ans++;
    }
    v1.erase(v1.begin(), v1.end());
    v2.erase(v2.begin(), v2.end());
  }
  cout<<ans<<endl;
  return 0;
} 

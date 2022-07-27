#include<bits/stdc++.h>
using namespace std;

string p[101][101];
string pr[101];

bool order(string s1, string s2) {
  for(int i = 0; i < s1.length(); i++) {
    if(s1[i] == s2[i]) {
      continue;
    }
    if(s1[i] < s2[i]) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}

int main() {
  int n, k;
  cin>>k>>n;

  unordered_map <string, int> mp;

  for(int i = 0; i < n; i++) {
    string name;
    cin>>name;
    mp.insert(pair<string, int>(name, 0));
    pr[i] = name;
  }

  for(int i = 0; i < k; i++) {
    for(int j = 0; j < n; j++) {
      string name;
      cin>>name;
      p[i][j] = name;
    }
  }

  int count = 0;
  for(int i = 0; i < k; i++) {
    int val = 1;
    for(int j = 0; j < n-1; j++) {
      if(order(p[i][j], p[i][j+1])) {
        if(j==0) {
          mp[p[i][j]] += val;
          mp[p[i][j+1]] += val;
        } else {
          mp[p[i][j+1]] += val;
        }
      } else {
        if(j==0) {
          mp[p[i][j]] += val;
          val++;
          mp[p[i][j+1]] += val;
        } else {
          val++;
          mp[p[i][j+1]] += val;
        }
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for (pair<string,int> x : mp) {
      if(x.first == pr[i]) {
        for(int j = 0; j < n; j++) {
          for (pair<string,int> y : mp) {
            if(y.first == pr[j]) {
              if(i == j) {
                cout<<'B';
              }
              else if(x.second > y.second) {
                cout<<1;
              }
              else if(x.second < y.second) {
                cout<<0;
              } else {
                cout<<'?';
              }
            }
          }
        }
      }
    }
    cout<<endl;
  }
  return 0;
} 

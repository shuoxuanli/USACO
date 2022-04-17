#include <bits/stdc++.h>
using namespace std;

char ttc[3][3];

int main() {
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);

  for(int i = 0; i < 3; i++) {
    string s;
    cin>>s;
    for(int j = 0; j < 3; j++) {
      ttc[i][j] = s[j];
    }
  }

  set<char> s1;
  for(int i = 0; i < 3; i++) {
    if(ttc[i][0] == ttc[i][1] && ttc[i][1] == ttc[i][2]) {
      s1.insert(ttc[i][0]);
    }
  }

  for(int i = 0; i < 3; i++) {
    if(ttc[0][i] == ttc[1][i] && ttc[1][i] == ttc[2][i]) {
      s1.insert(ttc[0][i]);
    }
  }

  if(ttc[0][0] == ttc[1][1] && ttc[1][1] == ttc[2][2]) {
    s1.insert(ttc[0][0]);
  }
  
  if(ttc[0][2] == ttc[1][1] && ttc[1][1] == ttc[2][0]) {
    s1.insert(ttc[0][2]);
  }

  cout<<s1.size()<<endl;

  set<char> s;
  set<string> v;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      s.insert(ttc[i][j]);
    }
    if(s.size() == 2) {
      string str;
      for(char c: s) {
        str += c;
      }
      v.insert(str);
    } 
    s.clear();
  }
  for(int j = 0; j < 3; j++) {
    for(int i = 0; i < 3; i++) {
      s.insert(ttc[i][j]);
    }
    if(s.size() == 2) {
      string str;
      for(char c: s) {
        str += c;
      }
      v.insert(str);
    } 
    s.clear();
  }

  s.insert(ttc[0][0]); 
  s.insert(ttc[1][1]); 
  s.insert(ttc[2][2]);
  if(s.size() == 2) {
    string str;
    for(char c: s) {
      str += c;
    }
    v.insert(str);
  } 
  s.clear();

  s.insert(ttc[0][2]); 
  s.insert(ttc[1][1]); 
  s.insert(ttc[2][0]);
  if(s.size() == 2) {
    string str;
    for(char c: s) {
      str += c;
    }
    v.insert(str);
  } 
  s.clear();  

  cout<<v.size()<<endl;
  return 0;
} 

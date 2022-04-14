#include <bits/stdc++.h>
using namespace std;

int cor[3][3], guess[3][3], cfreqs[26], gfreqs[26];

int main() {
  for(int i = 0; i < 3; i++) {
    string s;
    cin>>s;
    for(int j = 0; j < 3; j++) {
      cor[i][j] = s[j];
      cfreqs[s[j] - 'A']++;
    }
  }

  for(int i = 0; i < 3; i++) {
    string s; 
    cin>>s;
    for(int j = 0; j < 3; j++) {
      guess[i][j] = s[j];
      gfreqs[s[j] - 'A']++;
    }
  }

  int g = 0, y = 0;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(guess[i][j] == cor[i][j]) {
        g++;
        cfreqs[guess[i][j] - 'A']--;
        gfreqs[cor[i][j] - 'A']--;
      }
    }
  }

  for(int i = 0; i < 26; i++) {
    if(cfreqs[i] != 0) {
      y += min(cfreqs[i], gfreqs[i]);
    }
  }

  cout<<g<<endl;
  cout<<y<<endl;
  return 0;
} 

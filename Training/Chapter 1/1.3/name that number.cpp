/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: namenum
*/
#include<bits/stdc++.h>
using namespace std;

char phone[8][3] = {{'A','B','C'}, {'D','E','F'}, {'G','H','I'},{'J', 'K', 'L'}, {'M','N','O'}, {'P','R','S'}, {'T','U','V'}, {'W','X','Y'}};
int num[12];

int main() {
  ofstream fout ("namenum.out");
  ifstream fin ("namenum.in"), fdict ("dict.txt");

  string s;
  fin>>s;

  for(int i = 0; i < s.length(); i++) {
    num[i] = s[i] - 48;
  }

  bool ans = false;
  string d;
  while(fdict>>d) {
    if(d.length() != s.length()) {
      continue;
    } 
    int count = 0;
    for(int i = 0; i < d.length(); i++) {
      for(int j = 0; j < 3; j++) {
        if(phone[num[i]-2][j] == d[i]) {
          count++;
          break;
        }
      }
    }
    if(count != s.length()) {
      continue;
    } 
    fout<<d<<endl;
    ans = true;
  } 
  if(!ans) {
    fout<<"NONE"<<endl;
  }
  return 0;
}

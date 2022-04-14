#include<bits/stdc++.h>
using namespace std;

int l = 0, r = 0;
string s;

void checkLR (char pre, char loc){
  if(pre == 'N' && loc == 'E') r++;
  else if(pre == 'N' && loc == 'W') l++;  
  else if(pre == 'S' && loc == 'E') l++;
  else if(pre == 'S' && loc == 'W') r++; 
  else if(pre == 'E' && loc == 'S') r++;
  else if(pre == 'E' && loc == 'N') l++;  
  else if(pre == 'W' && loc == 'S') l++;
  else if(pre == 'W' && loc == 'N') r++; 
}

int main() {
  int n;
  cin>>n;
  for(int i = 0; i < n; i++) {
    l = 0;
    r = 0;
    cin>>s;
    char pre;
    for(int j = 0; j < s.length(); j++) {
      if(j == 0) {
        pre = s[j];
      } else {
        checkLR(pre, s[j]);
        pre = s[j];
      }
    }
    string ans =  (l < r) ? "CW":"CCW";
    cout<<ans<<endl;
  }  
  return 0;
} 

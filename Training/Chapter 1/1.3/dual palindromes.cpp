/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: dualpal
*/
#include<bits/stdc++.h>
using namespace std;

const string numbers = "0123456789ABCDEFGHIJK";
string convert (int input, int b) {
    string result = "";
    while (input > 0) {
        int remainder = input % b;
        result+=numbers[remainder];
        input-=remainder;
        input/=b;
    }
    return result;
}

bool palindrome (string s) {
  for(int i = 0; i < s.length(); i++) {
    if(s[i] != s[s.length()-1-i]) {
      return false;
    }
  }
  return true;
}

int main() {
  freopen("dualpal.in", "r", stdin);
  freopen("dualpal.out", "w", stdout);

  int n, num;
  cin>>n>>num;

  while(n > 0) {
    int j = num+2;
    for(int i = num+1; i < j; i++) {
      int tmp = 0;
      for(int k = 2; k <= 10; k++) {
        if(palindrome(convert(i, k))) {
          tmp++;
        }
      }
      if(tmp >= 2) {
        cout<<i<<endl;
        n--;
      }
      if(n <= 0) {
        break;
      }
      j++;
    }
  }
} 

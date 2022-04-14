#include<bits/stdc++.h>
using namespace std;

int main() {

  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);

  string str;
  cin>>str;

  int ans = 0;
  for(int i = 0; i < 52; i++) {
    int freqs[26];
    memset(freqs, 0, sizeof(freqs));
    int count = 0;
    for(int j = i+1; j < 52; j++) {
      while(str[j] != str[i]) {
        freqs[str[j] - 'A']++;
        break;
      }
      if(str[j] == str[i]) {
        for(int k = 0; k < 26; k++) {
          if(freqs[k] == 1) count++;
        }
      }
    }
    ans += count;
  }
  cout<<ans/2<<endl;
} 

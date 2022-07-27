#include <bits/stdc++.h>
using namespace std;

int n;
string t, s[4];

bool solve (string t) {
  do {
    bool b = 1;
    for(int i = 0; i < t.length(); i++) {
      bool a = 0;
      for(int j = 0; j < 6; j++) {
        a |= s[i][j]==t[i];
      }
      b &= a;
    }
    if(b) return true;
  } while (next_permutation(s, s + 4));
  return false;
}
  
int main() {
  cin>>n;

  for(int i = 0; i < 4; i++) cin>>s[i];

  sort(s, s+4);
  
  while(n--) {
    string t; cin>>t;
    cout<<(solve(t) ? "YES":"NO")<<endl;
    sort(s, s + 4);
  }
  return 0;
} 

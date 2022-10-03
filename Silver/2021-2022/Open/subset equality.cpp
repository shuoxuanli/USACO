#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int q;
bool ok[26][26];
string s, t, cmp;

int main() {
  cin>>s>>t;
  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < 26; j++) {
      string s1 = "", t1 = "";
      for(int k = 0; k < sz(s); k++) {
        if(s[k]-'a' == i || s[k]-'a' == j)
          s1 += s[k];
      }
      for(int k = 0; k < sz(t); k++) {
        if(t[k]-'a' == i || t[k]-'a' == j)
          t1 += t[k];
      }
      ok[i][j] = s1 == t1;
    }
  }
  cin>>q;
  while(q--) {
    cin>>cmp;
    bool b = 1;
    for(int i = 0; i < sz(cmp); i++) {
      for(int j = i; j < sz(cmp); j++) {
        b &= ok[cmp[i]-'a'][cmp[j]-'a'];
      }
    }
    cout<<(b ? 'Y' : 'N');
  }
  return 0;
}

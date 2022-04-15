#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
int prefix[maxN], suffix[maxN];
bool appear[26];

int main() {
  int n, q;
  cin>>n>>q;

  string s;
  cin>>s;

  for(int i = 1; i <= n; i++) {
    prefix[i] = prefix[i-1];
    if(!appear[s[i-1]-'A']) {
      prefix[i]++;
      appear[s[i-1]-'A'] = 1;
    }
    else {
      for(int j = i-2; j >= 0; j--) {
        if(s[j] == s[i-1]) {
          break;
        }
        if(s[j] < s[i-1]) {
          prefix[i]++;
          break;
        }
      }
    }
  }

  memset(appear, false, sizeof(appear));

  for(int i = n; i >= 1; i--) {
    suffix[i] = suffix[i+1];
    if(!appear[s[i-1]-'A']) {
      suffix[i]++;
      appear[s[i-1]-'A'] = 1;
    }
    else {
      for(int j = i; j < n; j++) {
        if(s[j] == s[i-1]) {
          break;
        }
        if(s[j] < s[i-1]) {
          suffix[i]++;
          break;
        }
      }
    }
  }

  for(int i = 0; i < q; i++) {
    int a,b;
    cin>>a>>b;

    int ans = prefix[a-1] + suffix[b+1];
    cout<<ans<<endl;
  }
} 

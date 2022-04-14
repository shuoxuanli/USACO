#include<bits/stdc++.h>
using namespace std;

int pos[1001];

int main() {
  string cowphabet;
  cin>>cowphabet;
  string fj;
  cin>>fj;

  for(int j = 0; j < fj.length(); j++) {
    for(int i = 0; i < 26; i++) {
      if(fj[j] == cowphabet[i]) {
        pos[j] = i;
      }
    }
  }

  int ans = 1;
  for(int i = 0; i < fj.length() - 1; i++) {
    if(pos[i] >= pos[i+1]) {
      ans++;
    }
  }

  cout<<ans<<endl;
  return 0;
} 

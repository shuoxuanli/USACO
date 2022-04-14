#include <bits/stdc++.h>
using namespace std;

int w[100001];

int main() {
  freopen("lemonade.in", "r", stdin);
  freopen("lemonade.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>w[i];
  }

  sort(w, w+n);

  int cnt = 0;
  for(int i = n-1; i >= 0; i--) {
    if(w[i] < cnt) {
      break;
    }
    cnt++;
  }

  cout<<cnt<<endl;
  return 0;
}

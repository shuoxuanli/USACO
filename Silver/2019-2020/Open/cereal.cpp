#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, m, a[100001], b[100001];
ll ans[100001], st[100001];

int main() {
  ifstream cin("cereal.in");
  ofstream cout("cereal.out");
  cin>>n>>m;
  for(int i = 0; i < n; i++) {
    cin>>a[i]>>b[i];
  }
  memset(st, -1, sizeof(st));
  ll cnt = 0;
  for(int i = n-1; i >= 0; i--) {
    int j = i, k = a[i];
    while(1) {
      if(st[k] == -1) {
        st[k] = j;
        cnt++;
        break;
      }
      if(st[k] < j) {
        break;
      } else {
        int tmp = j;
        j = st[k];
        st[k] = tmp;
        k = b[j];
      }
    }
    ans[i] = cnt;
  }
  for(int i = 0; i < n; i++) {
    cout<<ans[i]<<endl;
  }
  return 0;
}

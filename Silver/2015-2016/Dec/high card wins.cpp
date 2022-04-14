#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10;
vector<int> b, e;
bool cards[maxN];

int main() {
  freopen("highcard.in", "r", stdin);
  freopen("highcard.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    int card;
    cin>>card;
    cards[card] = 1;
  }

  for(int i = 1; i <= 2*n; i++) {
    if(cards[i]) {
      e.push_back(i);
    } else {
      b.push_back(i);
    }
  }

  sort(e.begin(), e.end());
  sort(b.begin(), b.end());

  int l = 0, r = 0, ans = 0;
  while(l < n && r < n) {
    while(b[r] < e[l]) {
      r++;
    }
    l++;
    r++;
    ans++;
  }

  cout<<ans<<endl;
  return 0;
} 

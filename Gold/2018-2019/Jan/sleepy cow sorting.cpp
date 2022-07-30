#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 1e5+1;
int n, a[maxN], c[maxN];

int lowbit(int x) {
  return x&(-x);
}

void upd(int x, int v) {
  for(int i = x; i <= n; i+=lowbit(i)) {
    c[i] += v;
  }
}

ll qry(int x) {
  ll ret = 0;
  for(int i = x; i > 0; i-=lowbit(i)) {
    ret += c[i];
  }
  return ret;
}

int main() {
  ifstream cin("sleepy.in");
  ofstream cout("sleepy.out");
  
  cin>>n;
  for(int i = 1; i <= n; i++) cin>>a[i];

  int sum = n;
  for(int i = n; i > 1; i--) {
    if(a[i] < a[i-1]) {
      upd(a[i], 1);
      sum--;
      break;
    }
    upd(a[i], 1);
    sum--;
  }

  vector<int> ans;
  for(int i = 1; i <= sum; i++) {
    ans.push_back(sum-i+qry(a[i]-1));
    upd(a[i], 1);
  }

  cout<<sum<<endl;
  for(int i = 0; i < ans.size()-1; i++) {
    cout<<ans[i]<<" ";
  }
  cout<<ans.back()<<endl;
  return 0;
} 

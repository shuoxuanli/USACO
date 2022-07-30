#include <bits/stdc++.h>
#define LL long long
using namespace std;

unordered_map<string, LL> mp;
LL n, ans;
string a[6];

int main() {
  freopen("cowpatibility.in", "r", stdin);
  freopen("cowpatibility.out", "w", stdout);
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin>>n;
	ans=n*(n-1)/2;
	for (int c=1; c<=n; c++) {
    for (int i=1;i<=5;i++) {
      cin>>a[i];
    }
		sort(a+1,a+6);
		LL sum=0;
		for (int i=1; i<=31; i++) {
			int cnt=0;
      string key="";
		  for(int j = 1; j <= 5; j++) {
        if(i&(1<<(j-1))) {
          cnt++;
          key += " " + a[j];
        }
      }
      if(cnt&1) sum += mp[key];
      else sum -= mp[key];
      mp[key]++;
    }
    ans -= sum;
  }
  
  cout<<ans<<endl;
  return 0;
}

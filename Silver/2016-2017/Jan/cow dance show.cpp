#include <bits/stdc++.h>
using namespace std;

int n, tmax;
int t[10001];

bool check(int k) {
	 int a[k];
   for(int i = 0; i < k; i++) {
     a[i] = t[i];
   }

  for(int i = k; i < n; i++) {
    sort(a, a+k);
    a[0] += t[i];
  }

  sort(a, a+k);
  return tmax >= a[k-1];
}

int main() {
	freopen("cowdance.in","r",stdin);
	freopen("cowdance.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>tmax;
	for(int i=0; i<n; i++) {
		cin>>t[i];
	}
	int left = 1, right = n, ans = n;
	while(left<=right) {
		int mid = (left+right)/2;
		if(check(mid)) {
      ans = mid;
      right = mid-1;
    } else {
      left = mid+1;
    }
	}
	cout<<ans<<endl;

	return 0;
}

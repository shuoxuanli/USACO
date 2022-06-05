#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int t, n;
ll a[1000001], diff[100001];

int main() {	
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 0; i < n; i++) 
			cin>>a[i];

			ll d = 0; 
			for(int i = 0; i < n; i++) {
				if(i&1) d -= a[i];
				else d += a[i];
			}

			bool b = 1;
			for(int i = 0; i < n; i++) {
				diff[i] = a[i] - d;
			}

			for(int i = 1; i < n; i++) {
				diff[i] -= diff[i-1];
				b &= diff[i] >= 0;
			}

			if(n&1)
				b &= d >= 0;
			else 
				b &= d == 0;

			if((n&1)^1) {
				ll mn = LLONG_MAX;
				for(int i = 0; i < n; i += 2) 
					mn = min(mn, diff[i]);
				for(int i = 0; i < n; i += 2) 
					diff[i] -= mn;
			}

			ll ans = accumulate(diff, diff+n, 0ll)*2;

			cout<<(b ? ans : -1)<<endl;
	}
}

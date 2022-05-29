#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int main() {
	int n;
	cin>>n;
	while(n--) {
		ll a, b;
		cin>>a>>b;
		
		if(a == b) {
			cout<<0<<endl;
			continue;
		}

		vector<ll> da = {a}, db = {b};

		while(a > 1) {
			if(a&1) {
				a++;
			} else {
				a>>=1;
			}
			da.push_back(a);
		}
		da.push_back(1);

		while(b > 1) {
			if(b&1) {
				b--;
			} else {
				b >>= 1;
			}
			db.push_back(b);
		}
		db.push_back(1);
	

		ll ans = LLONG_MAX;
		for(int i = 0; i < sz(da); i++) {
			for(int j = 0; j < sz(db); j++) {
				if(da[i] < db[j]) {
					ans = min(ans, db[j]-da[i]+i+j);
				}
			}
		}

		cout<<ans<<endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n;
int a[200001], last[200001];
ll c[200001];

void upd(int u, int v) {
	for(int i = u; i <= n; i += i&-i) 
		c[i] += v;
}

ll qry(int u) {
	ll ret = 0;
	for(int i = u; i > 0; i -= i&-i) {
		ret += c[i];
	}
	return ret;
}

int main() {
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];

	map<int, int> mp;
	for(int i = 1; i <= n; i++) {
		if(!mp.count(a[i]))
			last[i] = -1;
		else
			last[i] = mp[a[i]];
		mp[a[i]] = i;
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		if(last[i] != -1)
			upd(last[i], -1);
		ans += qry(i)-qry(last[i]);
		upd(i, 1);
	}

	cout<<ans<<endl;
	return 0;
}

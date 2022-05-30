#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())

int n, m, k, l, r, a[101], a2[101];;
vector<int> v[101];

bool chk(int t, int p) {
	if(a[p] >= t) {
		a[p] -= t;
		return 1;
	}
	t -= a[p], a[p] = 0;
	bool b = !v[p].empty();
	for(int i = 0; i < sz(v[p]); i++) {
		b &= chk(t, v[p][i]);
	}
	return b;
}

int main() {
	cin>>n;
	for(int i = 1; i <= n; i++) 
		cin>>a2[i];
	cin>>k;
	for(int i = 0; i < k; i++) {
		cin>>l>>m;
		for(int j = 0; j < m; j++) {
			cin>>r;
			v[l].push_back(r);
		}
	}

	int ans = 0;
	while(1) {
		memcpy(a, a2, sizeof(a));
		if(!chk(++ans, n)) {
			cout<<ans-1<<endl;
			break;
		}
	}
	return 0;
}

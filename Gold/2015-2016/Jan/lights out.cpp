#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, x[205], y[205];
ll theta[205], cw[205], ccw[205];

int main() {
	ifstream cin("lightsout.in");
	ofstream cout("lightsout.out");

	cin>>n;
	for(int i = 0; i < n; i++) {
		cin>>x[i]>>y[i];
	}

	for(int i = 1; i < n; i++) {
		int dx1 = x[i] - x[i-1];
		int dx2 = x[(i+1)%n] - x[i];
		int dy1 = y[i] - y[i-1];
		int dy2 = y[(i+1)%n] - y[i];

		cw[i] = cw[i-1] + abs(dx1) + abs(dy1);

		if(dx1 == 0) {
			if(dy1 > 0) 
				theta[i] = (dx2 > 0);
			else
				theta[i] = (dx2 < 0);
		} else {
			if(dx1 > 0)
				theta[i] = (dy2 < 0);
			else
				theta[i] = (dy2 > 0);
		}
	}

	for(int i = n-1; i > 0; i--) {
		int dx = x[(i+1)%n] - x[i];
		int dy = y[(i+1)%n] - y[i];

		ccw[i] = ccw[(i+1)%n] + abs(dx) + abs(dy);
	}

	unordered_map<string, int> mp;
	for(int i = 1; i < n; i++) {
		string s = "";
		for(int j = i; j < n; j++) {
			s += to_string(theta[j]) + " ";
			mp[s]++;
			if(j < n)
				s += to_string(cw[j+1] - cw[j]) + " ";
		}
	}

	ll ans = 0;
	for(int i = 1; i < n; i++) {
		string s = "";
		ll cur; int j;
		for(j = i; j < n; j++) {
			s += to_string(theta[j]) + " ";
			if(mp[s] == 1) {
				break;
			}
			if(j < n)
				s += to_string(cw[j+1] - cw[j]) + " ";
		}
		if(j == n) 
			cur = ccw[i] - min(ccw[i], cw[i]);
		else
			cur = cw[j] - cw[i] + min(cw[j], ccw[j]) - min(cw[i], ccw[i]);
		ans = max(ans, cur);
	}
	cout<<ans<<endl;
	return 0;
}

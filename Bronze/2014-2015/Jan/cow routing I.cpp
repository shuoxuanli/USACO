#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);

	int n, a, b;
	cin>>a>>b>>n;

	int ans = INT_MAX;
	for(int i = 0; i < n; i++) {
		int cost, m;
		cin>>cost>>m;
		int tmp = -1;
		int tmp2 = -1;
		for(int j = 0; j < m; j++) {
			int city;
			cin>>city;
			if(city == a) {
				tmp = j;
			} 
			else if(city == b) {
				tmp2 = j;
			}
		}
		if(tmp < tmp2 && tmp != -1 && tmp2 != -1) {
			ans = min(ans, cost);
		}
	}

	ans = (ans==INT_MAX) ? -1:ans;
	cout<<ans<<endl;
	return 0;
}

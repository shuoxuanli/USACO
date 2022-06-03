#include<bits/stdc++.h>
using namespace std;

int n,m;
int grid1[500][500], grid2[500][500];
bool can1[20001], can2[20001];


void dfs(int currV, int currD) {
	if(currV == n-1) {
		can1[currD] = true;
		return;
	}
	for(int i = currV + 1; i < n; i++) {
		if(grid1[currV][i] > 0) {
			dfs(i, currD + grid1[currV][i]);
		}
	}
}

void dfs2(int currV, int currD) {
	if(currV == n-1) {
		can2[currD] = true;
		return;
	}
	for(int i = currV + 1; i < n; i++) {
		if(grid2[currV][i] > 0) {
			dfs2(i, currD + grid2[currV][i]);
		}
	}
}

int main() {
	freopen("meeting.in", "r", stdin);
	freopen("meeting.out", "w", stdout);
	cin>>n>>m;

	for(int i = 0; i < m; i++) {
		int x, y;
		cin>>x>>y>>grid1[x-1][y-1]>>grid2[x-1][y-1];
	}

	dfs(0,0);
	dfs2(0,0);

	int ans = INT_MAX;
	for(int i = 0; i < 20000; i++) {
		if(can1[i] && can2[i]) {
			ans = i;
			break;
		}
	}

	if(ans == INT_MAX) {
		cout<<"IMPOSSIBLE"<<endl;
	} else {
		cout<<ans<<endl;
	}
	return 0;
} 

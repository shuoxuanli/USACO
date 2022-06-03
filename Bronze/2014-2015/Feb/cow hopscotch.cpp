#include <bits/stdc++.h>
using namespace std;

char grid[16][16];
int ans = 0;
int r, c;

void dfs(int a, int b) {
	if(a == r-1 && b == c-1) {
		ans++;
		return;
	}
	for(int i = a+1; i < r; i++) {
		for(int j = b+1; j < c; j++) {
			if(grid[i][j] != grid[a][b] && i != a && j != b) {
				dfs(i, j);
			}
		}
	}
}

int main() {
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);

	cin>>r>>c;

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin>>grid[i][j];
		}
	}

	dfs(0,0);

	cout<<ans<<endl;
	return 0;
} 

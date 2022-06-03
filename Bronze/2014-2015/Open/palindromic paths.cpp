#include <bits/stdc++.h>
using namespace std;

int n;
char paths[18][18];
unordered_set<string> rows1[18];
unordered_set<string> rows2[18];

void dfs(int x, int y, string curr) {
	if(x + y == n-1) {
		rows1[x].insert(curr + paths[x][y]);
	} else {
		dfs(x+1, y, curr+paths[x][y]);
		dfs(x, y+1, curr+paths[x][y]);
	}
} 

void dfs2(int x, int y, string curr) {
	if(x + y == n-1) {
		rows2[x].insert(curr + paths[x][y]);
	} else {
		dfs2(x+1, y, curr+paths[x][y]);
		dfs2(x, y+1, curr+paths[x][y]);
	}
} 

void transpose() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i + j >= n-1){
				continue;
			}
		swap(paths[i][j], paths[n-1-j][n-1-i]);
		}
	}
}

int main() {
	ifstream cin("palpath.in");
	ofstream cout("palpath.out");

	cin>> n;

	for(int i = 0; i < n; i++) {
		string s;
		cin>>s;
		for(int j = 0; j < n; j++) {
			paths[i][j] = s[j];
		}
	}

	dfs(0,0, "");
	transpose();
	dfs2(0,0,"");

	set<string> ans;
	for(int i = 0; i < n; i++) {
		for(string s: rows1[i]) {
			if(rows2[i].count(s)) {
				ans.insert(s);
			}
		}
	}

	cout<<ans.size()<<endl;
	return 0;
} 

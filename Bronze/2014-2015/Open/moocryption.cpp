#include <bits/stdc++.h>
using namespace std;

char puzzle[51][51];
char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int main() {
	freopen("moocrypt.in", "r", stdin);
	freopen("moocrypt.out", "w", stdout);

	int n, m;
	cin>>n>>m;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin>>puzzle[i][j];
		}
	}
	
	int cnt = 0;
	for(int k = 0; k < 26; k++) { 
		for(int l = 0; l < 26; l++) {
			if(k != l && alphabet[k] != 'M' && alphabet[l] != 'O') {
				int ans = 0;
				for(int i = 0; i < n; i++) {
					for(int j = 0; j <  m; j++) {
						if(j < m-2 && puzzle[i][j+1] == puzzle[i][j+2] && alphabet[l] == puzzle[i][j+1] && puzzle[i][j] == alphabet[k]) {
							ans++;
						}
						if(j > 1 && puzzle[i][j-1] == puzzle[i][j-2] && alphabet[l] == puzzle[i][j-1] && puzzle[i][j] == alphabet[k]) {
							ans++;
						}
						if(i < n-2 && puzzle[i+1][j] == puzzle[i+2][j] && alphabet[l] == puzzle[i+1][j] && puzzle[i][j] == alphabet[k]) {
							ans++;
						}
						if(i > 1 && puzzle[i-1][j] == puzzle[i-2][j] && puzzle[i-1][j] == alphabet[l] && puzzle[i][j] == alphabet[k]) {
							ans++;
						}
						if(i > 1 && j < m-2 && puzzle[i-1][j+1] == puzzle[i-2][j+2] && alphabet[l] == puzzle[i-1][j+1] && puzzle[i][j] == alphabet[k]) {
							ans++;
						}
						if(i > 1 && j > 1 && puzzle[i-1][j-1] == puzzle[i-2][j-2] && alphabet[l] == puzzle[i-1][j-1] && puzzle[i][j] == alphabet[k]) {
							ans++;
						}
						if(i < n-2 && j > 1 && puzzle[i+1][j-1] == puzzle[i+2][j-2] && alphabet[l] == puzzle[i+1][j-1] && puzzle[i][j] == alphabet[k]) {
							ans++;
						}
						if(i < n-2 && j < m-2 && puzzle[i+1][j+1] == puzzle[i+2][j+2] && alphabet[l] == puzzle[i+1][j+1] && puzzle[i][j] == alphabet[k]) {
							ans++;
						}
					}
				}
				cnt = max(cnt, ans);
			}
		}
	}

	cout<<cnt<<endl;
	return 0;
} 

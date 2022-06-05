#include<bits/stdc++.h>
using namespace std;

int drink[1001][3], sick[51][2], milk[60];
bool dk[51];

int main() {
	freopen("badmilk.in", "r", stdin);
	freopen("badmilk.out", "w", stdout);

	int n, m, d, s;
	cin>>n>>m>>d>>s;

	for(int i = 0; i < d; i++) {
		cin>>drink[i][0]>>drink[i][1]>>drink[i][2];
	}
	for(int i = 0; i < s; i++) {
		cin>>sick[i][0]>>sick[i][1];
	}

	int count = 0;
	for(int i = 0; i < s; i++) {
		for(int j = 0; j < d; j++) {
			if(drink[j][0] == sick[i][0]) {
				count++;
				for(int k = 0; k < d; k++) {
					if(drink[k][2] < sick[i][1] && drink[k][0] == sick[i][0]) {
						milk[drink[k][1]]++;
					}
				}
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= m; i++) {
		int a = 0;
		if(milk[i] >= count) {
			for(int j = 0; j < d; j++) {
				if(drink[j][1] == i && dk[drink[j][0]] == false) {
					dk[drink[j][0]] = true;
					a++;
				}
			}
			ans = max(a, ans);
		}
	}

	cout<<ans<<endl;
	return 0;
} 

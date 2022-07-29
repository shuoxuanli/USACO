#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, k, a[201];
ll pre[201][201], dp[201][201][11];

void solve(int st) {
	for(int i = st; i < n+st; i++) {
		for(int j = 1; j < k; j++) {
			for(int l = i+1; l <= n+st; l++) {
				dp[st][l][j+1] = min(dp[st][l][j+1], dp[st][i][j] + pre[i][l]);	
			}
		}
	}
}

int main() {
	ifstream cin("cbarn2.in");
	ofstream cout("cbarn2.out");

	cin>>n>>k;
	for(int i = 1; i <= n; i++) 
		cin>>a[i];
	for(int i = n+1; i <= (n<<1); i++)
		a[i] = a[i-n]; 

	for(int i = 1; i <= (n<<1); i++) {
		for(int j = i; j < min(i+n, (n<<1)+1); j++) {
			for(int l = i; l <= j; l++) {
				pre[i][j+1] += a[l]*(l-i);
			}
		}
	}

	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= i+n; j++) {
			dp[i][j][1] = pre[i][j];
		}
	}

	for(int i = 1; i <= n; i++) 
		solve(i);
	
	ll ans = LLONG_MAX;
	for(int i = 1; i <= n; i++)
		ans = min(ans, dp[i][i+n][k]);
	cout<<ans<<endl;
	return 0;
}

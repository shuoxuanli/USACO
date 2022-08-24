#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ar array
#define vt vector
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define db double
#define ll long long
#define ld long double
#define pi pair<int, int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+5, MOD = 1e9+7;
int t, n, m, k, q;
ll a[N];
//string s;
vt<pi> adj[N];
//bool vis[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	t = 1;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}

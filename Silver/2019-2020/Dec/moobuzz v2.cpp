#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
 
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

vi stor;
 
bool ok(int x) { return x%3 && x%5; }

int solve(int N) { 
	int num = (N-1)/8;
	return stor[N-8*num-1]+15*num;
}
 
int main() {
	setIO("moobuzz");
	FOR(i,1,16) if (ok(i)) stor.pb(i);
	int N; cin >> N;
	cout << solve(N) << "\n";
}

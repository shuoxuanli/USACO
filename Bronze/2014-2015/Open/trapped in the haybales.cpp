#include <bits/stdc++.h>
using namespace std;

struct haybale{
	int size, pos;
};

int n;
haybale bales[4001];
bool can[4001];

bool cmp(haybale a, haybale b) {
	return a.pos < b.pos;
}

int main() {
	freopen("trapped.in", "r", stdin);
	freopen("trapped.out", "w", stdout);

	cin>>n;

	for(int i = 0; i < n; i++) {
		cin>>bales[i].size>>bales[i].pos;
	}

	sort(bales, bales+n, cmp);

	int ans = 0;
	for(int i = 0; i < n-1; i++) {
		int interval = bales[i+1].pos - bales[i].pos;
		int left = i;
		int right = i+1;
		while(left >= 0 && right <= n-1){
			bool broke = false;
			int curr = bales[right].pos - bales[left].pos;
			if(curr > bales[left].size) {
				left--;
				broke = true;
			}
			if(curr > bales[right].size) {
				right++;
				broke = true;
			}
			if(!broke) {
				break;
			}
		}
		if(left >= 0 && right <= n-1) {
			ans += interval;
		}
	}
	cout<<ans<<endl;
	return 0;
} 

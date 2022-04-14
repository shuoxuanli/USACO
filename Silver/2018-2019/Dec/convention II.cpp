#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	
	int n;
	vector<vector<int>> cows;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, duration;
		cin >> start >> duration;
		cows.push_back({i, start, duration});
	}

	sort(cows.begin(), cows.end(), [](const vector<int> &a, const vector<int> &b) {
		return a[1] < b[1];
	});

	int time = 0, cur = 0, ans = 0;
	
	set<vector<int>> waiting;
	while (cur < n || waiting.size() > 0) {
		if (cur < n && cows[cur][1] <= time) {
			waiting.insert(cows[cur]);
			cur++;
		} else if (waiting.size() == 0) {
			time = cows[cur][1] + cows[cur][2];
			cur++;
		} else {
			vector<int> next = *waiting.begin();
			ans = max(ans, time - next[1]);
			time += next[2];
			waiting.erase(waiting.begin());
		}
	}
	cout << ans << '\n';
}

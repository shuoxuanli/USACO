#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	int n;
	cin >> n;
	int herd[100005];
	for (int i = 0; i < n; ++i) {
		cin >> herd[i];
	}
	sort(herd, herd + n);

	int tot = 0;
	for (int i = 1; i < n; ++i) {
		tot += herd[i] - herd[i - 1] - 1;
	}
  
	int minAns = INT_MAX;
	if (herd[n - 2] - herd[0] == n - 2 && herd[n - 1] - herd[n - 2] > 2) {
		minAns = 2;
	} else if (herd[n - 1] - herd[1] == n - 2 && herd[1] - herd[0] > 2) {
		minAns = 2;
	} else {
		int j = 0;
		for (int i = 0; i < n; ++i) {
			while (j + 1 < n && herd[j + 1] - herd[i] < n) {
				j++;
			}
			minAns = min(minAns, n - (j - i + 1));
		}
	}
	int maxAns = max(tot - (herd[1] - herd[0] - 1), tot - (herd[n - 1] - herd[n - 2] - 1));
	cout << minAns << "\n" << maxAns;
}

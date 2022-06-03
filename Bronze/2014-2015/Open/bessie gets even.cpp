#include <bits/stdc++.h>
using namespace std;


int num[256][2];

bool is_even(int x) {
	return x % 2 == 0;
}

int main() {
	freopen("geteven.in", "r", stdin);
	freopen("geteven.out", "w", stdout);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		char letter;
		int val;
		cin >> letter >> val;

		if (is_even(val)) {
			num[letter][0]++;
		} else {
			num[letter][1]++;
		}
	}

	int result = 0;
	for(int B = 0; B < 2; B++)
	for(int E = 0; E < 2; E++)
	for(int S = 0; S < 2; S++)
	for(int I = 0; I < 2; I++)
	for(int G = 0; G < 2; G++)
	for(int O = 0; O < 2; O++)
	for(int M = 0; M < 2; M++) {
		if (is_even((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O))) {
			result += num['B'][B] * num['E'][E] * num['S'][S] * num['I'][I] * num['G'][G] * num['O'][O] * num['M'][M];
		}
	}
	cout << result << endl;

	return 0;
}

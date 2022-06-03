#include <iostream>
#include <cstdio>

using namespace std;

#define MAXB 15000

int evaluate(const string& num, int base) {
	return (num[0] - '0') * base * base + (num[1] - '0') * base + (num[2] - '0');
}

int main() {
	freopen("whatbase.in", "r", stdin);
	freopen("whatbase.out", "w", stdout);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		string x, y;
		cin >> x >> y;

		int X = 10;
		int Y = 10;
		while (X <= MAXB && Y <= MAXB) {
			int numX = evaluate(x, X);
			int numY = evaluate(y, Y);
			if (numX < numY) {
				X++;
			} else if (numY < numX) {
				Y++;
			} else {
				cout << X << ' ' << Y << '\n';
				break;
			}
		}
	}
	return 0;
}

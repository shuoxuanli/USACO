#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 755;
int n, a[N][N], d[N][N];

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            char c;
            cin >> c;
            a[i][j] = c == '1';
        }
    }

    int ans = 0;
    for (int x = 1; x < n; x++) {
        for (int i = 1; i <= n - x; i++) {
            d[i][i + x] = a[i][i + x];
            for (int k = i + 1; k < i + x; k++) {
                d[i][i + x] ^= d[i][k] & a[k][i + x];
            }
            ans += d[i][i + x];
        }
    }

    cout << ans << '\n';
    return 0;
}

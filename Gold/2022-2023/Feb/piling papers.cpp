#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int MOD = 1E9 + 7;
int n, q, a[301];
ll A, B;

vector<int> digits(ll x) {
    vector<int> d;
    while (x) {
        d.push_back(x % 10);
        x /= 10;
    }
    reverse(d.begin(), d.end());
    return d;
}

int cmp(int x, int y) {
    return (x > y) - (x < y) + 1;
}

vector<vector<int>> work(vector<int> d) {
    int m = sz(d);
    vector ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        vector dp(m, vector(m, vector<ll>(3)));
        for (int j = i; j < n; j++) {
            for (int x = 0; x < m; x++) {
                for (int y = m - 1; y > x; y--) {
                    if (a[j] < d[x]) {
                        for (int c = 0; c <= 2; c++) {
                            dp[x][y][0] += dp[x + 1][y][c];
                        }
                    } else if (a[j] == d[x]) {
                        for (int c = 0; c <= 2; c++) {
                            dp[x][y][c] += dp[x + 1][y][c];
                        }
                    } else {
                        for (int c = 0; c <= 2; c++) {
                            dp[x][y][2] += dp[x + 1][y][c];
                        }
                    }
                    dp[x][y][2] += dp[x][y - 1][2];
                    dp[x][y][0] += dp[x][y - 1][0];
                    dp[x][y][cmp(a[j], d[y])] += dp[x][y - 1][1];
                    for (int c = 0; c <= 2; c++) dp[x][y][c] %= MOD;
                }
            }
            for (int x = 0; x < m; x++) {
                dp[x][x][cmp(a[j], d[x])] = (dp[x][x][cmp(a[j], d[x])] + 2) % MOD;
            }
            for (int x = 0; x < m; x++) {
                ans[i][j] = (ans[i][j] + dp[x][m - 1][0]) % MOD;
                ans[i][j] = (ans[i][j] + dp[x][m - 1][1]) % MOD;
                if (x) {
                    ans[i][j] = (ans[i][j] + dp[x][m - 1][2]) % MOD;
                }
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> A >> B;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto lo = work(digits(A - 1));
    auto hi = work(digits(B));

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r, l--, r--;
        cout << (hi[l][r] - lo[l][r] + MOD) % MOD << '\n';
    }
    return 0;
}

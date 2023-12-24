#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 1E5 + 5;
int t, c, s[N], cnt[N][5], vis[2 * N];
bool has[2 * N];

int main() {
    cin >> t >> c;
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        has[a + N] = true;
    }
    for (int i = 0; i < c; i++) {
        char v;
        cin >> v;
        s[i] = v == 'F' ? 0 : (v == 'L' ? -1 : 1);
    }

    int ans = 0;
    for (int j = 0; j <= 4; j++) {
        int x = j - 2;
        for (int i = 0; i < c; i++) {
            x += s[i];
            if (s[i] == 0 && has[x + N]) {
                vis[x + N]++;
                cnt[0][j] += vis[x + N] == 1;
            }
        }
        x = 0;
        for (int i = 0; i < c; i++) {
            x += s[i];
            cnt[i + 1][j] = cnt[i][j];
            if (s[i] == 0 && has[x + j - 2 + N]) {
                cnt[i + 1][j] -= vis[x + j - 2 + N] == 1;
                vis[x + j - 2 + N]--;
            }
            if (s[i] == 0 && has[x + N]) {
                vis[x + N]++;
                cnt[i + 1][j] += vis[x + N] == 1;
            }
            if (abs(s[i] + j - 2) <= 1) {
                if (j - 2 == 0) {
                    ans = max(ans, cnt[i][j]);
                } else {
                    int cur = cnt[i][j];
                    if (s[i] == 0 && has[x + N]) {
                        cur -= vis[x + N] == 1;
                    }
                    if (s[i] + j - 2 == 0 && has[x - s[i] + N]) {
                        cur += vis[x - s[i] + N] == 0;
                    }
                    ans = max(ans, cur);
                }
            }
        }
        memset(vis, 0, sizeof(vis));
    }

    cout << ans << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n;
string s;

int main() {
    cin >> n >> s;

    int len = 0, day = 1E9;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == '0') {
            if (len == 0) continue;
            if (len == i || i == n) {
                day = min(day, len - 1);
            } else {
                day = min(day, (len - 1) / 2);
            }
            len = 0;
        } else {
            len++;
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == '0') {
            ans += (len + 2 * day) / (2 * day + 1);
            len = 0;
        } else {
            len++;
        }
    }

    cout << ans << '\n';
    return 0;
}

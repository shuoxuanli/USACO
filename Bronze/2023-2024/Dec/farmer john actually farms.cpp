#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 2E5 + 1;
int t, n, h[N], a[N], pos[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
 
    int l = 0, r = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        int x = h[pos[i]] - h[pos[i + 1]];
        int y = a[pos[i]] - a[pos[i + 1]];

        if (y > 0) {
            l = max(l, max(0, (y - x) / y));
        } else {
            if (x < 0 || (x == 0 && y == 0)) {
                r = INT_MIN;
            } else if (y != 0) {
                r = min(r, max(0, (x - 1) / -y));
            }
        }
    }

    cout << (l <= r ? l : -1) << '\n';
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, q, ord[150001];
ll a[150001], b[150001], p[150001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i * b[i];
        p[i] = p[i-1] + b[i];
    }

    cin >> q;
    while (q--) {
        int i; ll j;
        cin >> i >> j;

        int pre = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        int cur = lower_bound(b + 1, b + 1 + n, j) - b - (a[i] < j);

        if (a[i] < j) {
            cout << ans - pre * a[i] + cur * j - p[cur] + p[pre] << '\n';
        } else {
            cout << ans - pre * a[i] + cur * j + p[pre-1] - p[cur-1] << '\n';
        }
    }
    return 0;
}

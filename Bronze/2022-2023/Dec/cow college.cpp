#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, c[100001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    sort(c, c + n);

    ll tot = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        ll ct = 1LL * (n - i) * c[i];
        if (ct > tot) {
            tot = ct;
            ans = c[i];
        }
    }

    cout << tot << ' ' << ans << '\n';
    return 0;
}

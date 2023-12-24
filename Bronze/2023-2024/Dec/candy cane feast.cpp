#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<ll, ll>> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i].second;
    }

    for (auto [x, y] : b) {
        for (int i = 0; i < n && x < y; i++) {
            ll add = max(0LL, min(y, a[i]) - x);
            x += add;
            a[i] += add;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}

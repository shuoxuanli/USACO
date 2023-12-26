#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, m, k;
pair<int, int> a[200001];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    
    ll ans = 0;
    set<pair<int, int>> s;
    s.insert({INT_MIN, m});
    for (int i = 0; i < n; i++) {
        int cur = 0;
        auto [x0, y0] = a[i];
        auto it = s.upper_bound({x0 - k, INT_MAX});
        while (it != s.begin() && y0 > 0) {
            auto [x1, y1] = *prev(it);
            int mn = min(y1, y0);
            y1 -= mn;
            y0 -= mn;
            cur += mn;
            it = s.erase(prev(it));
            if (y1 > 0) {
                s.insert({x1, y1});
            }
        }
        ans += cur;
        s.insert({x0, cur});
    }

    cout << ans << '\n';
    return 0;
}

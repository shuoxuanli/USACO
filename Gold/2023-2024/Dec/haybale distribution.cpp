#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 1E6 + 5;
int n, q;
ll x[N], pre[N], suf[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x + n);

    for (int i = 0, j = 0; i <= x[n - 1]; i++) {
        pre[i] = (i ? pre[i - 1] : 0LL) + j;
        while (x[j] == i) j++;
    }
    for (int i = x[n - 1], j = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + n - j - 1;
        while (x[j] == i) j--;
    }

    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        auto calc = [&](int i) {
            return pre[i] * a + suf[i] * b;
        };

        int l = 0, r = x[n - 1];
        while (l < r) {
            int mid = (l + r) / 2;
            if (calc(mid) < calc(mid + 1)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << calc(l) << '\n';
    }
    return 0;
}

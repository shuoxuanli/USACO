#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 1E6 + 1;
int n, k, a[N], b[N], pa[N], pb[N], cnt[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        pa[a[i]] = i;
        a[i + k] = a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
        pb[b[i]] = i;
    }

    int add = 0;
    for (int i = 1; i <= n; i++) {
        if (!pa[i] && !pb[i]) {
            add++;
        }
    }

    int ans = 0;
    for (int t = 0; t < 2; t++) {
        int cur = 0;
        for (int i = 1, j = 0; i <= 2 * k; i++, j = j % k + 1) {
            if (a[i] != b[j]) {
                cnt[(i - j + k) % k] += cur;
                cur = 0;
                j = pb[a[i]];
            }
            cur += a[i] == b[j];
            if (i == 2 * k) {
                cnt[(i - j + k) % k] += cur;
            }
        }
        reverse(b + 1, b + 1 + k);
        for (int i = 1; i <= k; i++) {
            pb[b[i]] = i;
            ans = max(ans, cnt[i - 1] / 2);
            cnt[i - 1] = 0;
        }
    }

    cout << ans + add << '\n';
    return 0;
}

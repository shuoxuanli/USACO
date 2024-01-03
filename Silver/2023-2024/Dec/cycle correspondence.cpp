#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 5E5 + 1;
int n, k, a[N], b[N], pa[N], pb[N], cnt[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        pa[a[i]] = i;
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
        for (int i = 1; i <= k; i++) {
            if (pb[a[i]]) {
                cnt[(i - pb[a[i]] + k) % k]++;
            }
        }
        for (int i = 1; i <= k; i++) {
            pb[b[k - i + 1]] = i;
            ans = max(ans, cnt[i - 1]);
            cnt[i - 1] = 0;
        }
    }

    cout << ans + add << '\n';
    return 0;
}

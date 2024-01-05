#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 2E5 + 5;
int n, m, deg[N];
vector<ll> ans[N];
vector<pair<int, int>> adj[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        adj[b].push_back({a, l});
        deg[a]++;
    }

    vector<int> q0;
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) {
            q0.push_back(i);
            ans[i] = {0, 0, 0, 0};
        }
    }

    while (!q0.empty()) {
        vector<int> q1;
        for (int i = 0; i < sz(q0); i++) {
            int u = q0[i];
            for (auto [v, w] : adj[u]) {
                ans[v] = max(ans[v], {ans[u][0] + 1, -w, -i, ans[u][3] + w});
                if (!(--deg[v])) {
                    q1.push_back(v);
                }
            }
        }
        swap(q0, q1);
        sort(q0.begin(), q0.end(), [&](int u, int v) {
            return ans[u] > ans[v];
        });
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i][0] << ' ' << ans[i][3] << '\n';
    }
    return 0;
}

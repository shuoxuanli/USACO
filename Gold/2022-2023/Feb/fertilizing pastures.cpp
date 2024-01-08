#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

const int N = 2E5 + 1;
int n, t, dep[N], a[N];
ll sum[N], dis[N], dp[N][2];
vector<int> adj[N];

void dfs(int u) {
    sum[u] = a[u];
    for (int v : adj[u]) {
        dfs(v);
        sum[u] += sum[v];
        dep[u] = max(dep[u], dep[v] + 1);
    }
    sort(adj[u].begin(), adj[u].end(), [&](int x, int y) {
        return (dis[y] + 2) * sum[x] > (dis[x] + 2) * sum[y];
    });
    for (int v : adj[u]) {
        dp[u][0] += (dis[u] + 1) * sum[v] + dp[v][0];
        dis[u] += dis[v] + 2;
    }
    ll c = sum[u] - a[u], d = 0;
    dp[u][1] = dep[u] ? LLONG_MAX : 0LL;
    for (int v : adj[u]) {
        c -= sum[v];
        if (dep[u] == dep[v] + 1) {
            ll dec = c * (dis[v] + 2) + (d + 1) * sum[v] + dp[v][0];
            ll add = (dis[u] - dis[v] - 1) * sum[v] + dp[v][1];
            dp[u][1] = min(dp[u][1], dp[u][0] - dec + add);
        }
        d += dis[v] + 2;
    }
}

int main() {
    cin >> n >> t;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p >> a[i];
        adj[p].push_back(i);
    }
    dfs(1);
    cout << dis[1] - t * dep[1] << ' ' << dp[1][t] << '\n';
    return 0;
}

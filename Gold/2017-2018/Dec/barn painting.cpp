#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int n, k;

struct Edge {
  int to, next;
};

Edge e[N * 2];

int head[N], cnt = 0;
int colr[N];
LL dp[N][4];

void addEdge(int u, int v) {
  cnt++;
  e[cnt].to = v;
  e[cnt].next = head[u];
  head[u] = cnt;
}

void dfs(int cur, int fa) {
  if (colr[cur]) {
    dp[cur][colr[cur]] = 1;
  } else {
    dp[cur][1] = dp[cur][2] = dp[cur][3] = 1;
  }
  for (int i = head[cur]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs(v, cur);
    dp[cur][1] = dp[cur][1] * (dp[v][2] + dp[v][3]) % MOD;
    dp[cur][2] = dp[cur][2] * (dp[v][1] + dp[v][3]) % MOD;
    dp[cur][3] = dp[cur][3] * (dp[v][1] + dp[v][2]) % MOD;
  }
}

int main() {
  ifstream cin("barnpainting.in");
  ofstream cout("barnpainting.out");

  cin >> n >> k;
  for (int i = 1; i <= n - 1; i++) { 
    int u, v;
    cin >> u >> v;
    addEdge(u, v);
    addEdge(v, u);
  }

  for (int i = 1; i <= k; i++) {
    int id, c;
    cin >> id >> c;
    colr[id] = c;
  }

  dfs(1, -1);
  
  int ans = 0;
  for(int i = 1; i <= 3; i++) 
    ans = (ans+dp[1][i]) % MOD;
  cout << ans << endl;

  return 0;
}

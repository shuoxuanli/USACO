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

LL dfs(int curid, int curc, int fa, int fac) {
  if (curc == fac || (colr[curid] > 0 && curc != colr[curid])) { 
    return 0;
  }

  if (dp[curid][curc] > 0) {
    return dp[curid][curc];
  }

  dp[curid][curc] = 1;
  for (int i = head[curid]; i > 0; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) {
        continue;
    }
    LL num = 0;
    for (int j = 1; j <= 3; j++) {
      num += dfs(v, j, curid, curc);
      num %= MOD;
    }
    dp[curid][curc] *= num;
    dp[curid][curc] %= MOD;
  }
  return dp[curid][curc];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

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

  int ans = (dfs(1, 1, 0, 0) + dfs(1, 2, 0, 0)) % MOD;
  ans = (ans + dfs(1, 3, 0, 0)) % MOD;
  cout << ans << endl;

  return 0;
}

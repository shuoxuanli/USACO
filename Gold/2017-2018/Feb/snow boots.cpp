#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

struct tile {
  int f, id;
};

struct boot {
  int s, d, id;
};

tile tiles[N];
boot boots[N];
int n, b, f[N], siz[N], maxgap;
bool vis[N], ans[N];

inline int find(int x) {
  if (f[x] == x) {
    return x;
  }
  return f[x] = find(f[x]);
}

inline void merge(int u, int v) {
  int fu = find(u);
  int fv = find(v);
  if(fu != fv) {
    f[fu] = fv;
    siz[fv] += siz[fu];
  }
  return;
}

bool cmptile(const tile &a, const tile &b) { return a.f > b.f; }

bool cmpboot(const boot &a, const boot &b) { return a.s > b.s; }

int main() {
  freopen("snowboots.in", "r", stdin);
  freopen("snowboots.out", "w", stdout);
  cin>>n>>b;
  
  for (int i = 1; i <= n; i++) {
    int x;
    cin>>x;
    tiles[i] = {x, i};
    f[i] = i;
    siz[i] = 1;
  }
  
  for (int i = 1; i <= b; i++) {
    int s, d;
    cin>>s>>d;
    boots[i] = {s, d, i};
  }

  sort(tiles + 1, tiles + n + 1, cmptile);  
  sort(boots + 1, boots + b + 1, cmpboot);  

  int pos = 1;
  for(int i = 1; i <= b; i++) {
    while(pos <= n && tiles[pos].f > boots[i].s) {
      int id = tiles[pos].id;
      vis[id] = true;
      if(id > 1 && vis[id-1]) {
        merge(id, id-1);
      }
      if(id < n && vis[id+1]) {
        merge(id, id+1);
      }
      maxgap = max(maxgap, siz[find(id)]);
      pos++;
    }
    ans[boots[i].id] = (maxgap < boots[i].d);
  }
  
  for (int i = 1; i <= b; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}

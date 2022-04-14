#include <bits/stdc++.h>
using namespace std;

struct PCL {
  int i1,j1,i2,j2; 
};

int N, freqs[26];
string img[20];

vector<PCL> V;
bool vis[20][20];

void dfs(int i, int j, int c, int i1, int j1, int i2, int j2) {
  vis[i][j] = true;
  if (i > i1 && img[i-1][j]-'A'==c && !vis[i-1][j]) 
    dfs(i-1,j,c,i1,j1,i2,j2);
  if (i < i2 && img[i+1][j]-'A'==c && !vis[i+1][j]) 
    dfs(i+1,j,c,i1,j1,i2,j2);
  if (j > j1 && img[i][j-1]-'A'==c && !vis[i][j-1]) 
    dfs(i,j-1,c,i1,j1,i2,j2);
  if (j < j2 && img[i][j+1]-'A'==c && !vis[i][j+1]) 
    dfs(i,j+1,c,i1,j1,i2,j2);
}

bool find(int i1, int j1, int i2, int j2) {
  int color = 0;
  memset(vis, 0, sizeof(vis));
  memset(freqs, 0, sizeof(freqs));
  for (int i=i1; i<=i2; i++)
    for (int j=j1; j<=j2; j++)
      if (!vis[i][j]) {
      	int c = img[i][j] - 'A';
      	if (freqs[c] == 0) color++;
      	freqs[c]++;
      	dfs(i,j,c,i1,j1,i2,j2);
      }
  if (color != 2) return false;
  bool s = false, p =false;
  for (int i=0; i<26; i++) {
    if (freqs[i] == 1) s = true;
    if (freqs[i] > 1) p = true;
  }
  return s && p ;
}

bool rep(int x, int y) {
  return V[x].i1 >= V[y].i1 
    && V[x].i2 <= V[y].i2
    && V[x].j1 >= V[y].j1
    && V[x].j2 <= V[y].j2;
}

bool check(int x) {
  for (int i=0; i<V.size(); i++)
    if (i != x && rep(x,i)) return false;
  return true;
}

int main() {
  ifstream cin ("where.in");
  ofstream cout ("where.out");
  cin >> N;
  for (int i=0; i<N; i++)
    cin >> img[i];
  for (int i1=0; i1<N; i1++)
    for (int j1=0; j1<N; j1++)
      for (int i2=i1; i2<N; i2++)
      	for (int j2=j1; j2<N; j2++)
      	  if (find(i1,j1,i2,j2)) {
      	    PCL p = {i1,j1,i2,j2};
      	    V.push_back(p);
      	  }
  int ans = 0;
  for (int i=0; i<V.size(); i++)
    if (check(i)) ans++;
  cout << ans << "\n";
  return 0;
}

/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: wormhole
*/
#include<bits/stdc++.h>
using namespace std;

const int maxN = 15;
int N, X[maxN], Y[maxN];
int partner[maxN], r[maxN];

bool cycle() {
  for (int start=1; start<=N; start++) {
    int pos = start;
    for (int count=0; count<N; count++)
      pos = r[partner[pos]];
    if (pos != 0) return true;
  }
  return false;
}

int solve() {
  int i, total=0;
  for (i=1; i<=N; i++) 
    if (partner[i] == 0) break;

  if (i > N) {
    if (cycle()) return 1;
    else return 0;
  }

  for (int j=i+1; j<=N; j++)
    if (partner[j] == 0) {
      partner[i] = j;
      partner[j] = i;
      total += solve();
      partner[i] = partner[j] = 0;
    }
  return total;
}

int main() {
  ifstream fin("wormhole.in");
  fin >> N;
  for (int i=1; i<=N; i++) fin >> X[i] >> Y[i];
  fin.close();
  
  for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
      if (X[j] > X[i] && Y[i] == Y[j]) 
	if (r[i] == 0 || X[j]-X[i] < X[r[i]]-X[i])
	  r[i] = j;

  ofstream fout("wormhole.out");
  fout << solve() << "\n";
  return 0;
}

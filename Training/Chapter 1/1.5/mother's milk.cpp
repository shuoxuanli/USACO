/*
 ID: Shuoxuan Li [shuoxua2]
 LANG: C++11
 TASK: milk3
*/
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int SIZE = 25;
int al, bl, cl, at, bt, ct;
bool solutions[SIZE];
bool mark[SIZE][SIZE][SIZE];

pii move(int src, int dst, int dstl) {
  while (src > 0 && dst < dstl) { src--, dst++; }
  return make_pair(src, dst);
}

void solve(int a, int b, int c) {
  if (mark[a][b][c] == true)
    return;

  mark[a][b][c] = true;

  if (a == 0)
    solutions[c] = true;

  tie(ct,at) = move(c, a, al); solve(at, b, ct); 
  tie(ct,bt) = move(c, b, bl); solve(a, bt, ct); 
  tie(at,bt) = move(a, b, bl); solve(at, bt, c); 
  tie(at,ct) = move(a, c, cl); solve(at, b, ct); 
  tie(bt,at) = move(b, a, al); solve(at, bt, c); 
  tie(bt,ct) = move(b, c, cl); solve(a, bt, ct); 
}

int main() {
  ifstream cin("milk3.in");
  ofstream cout("milk3.out");

  cin >> al >> bl >> cl;
  solve(0, 0, cl);

  for (int i = 0, c = 1; i < SIZE; i++)
    if (solutions[i] == 1) {
      if(c > 1) cout << ' ';
      cout << i;
      c++;
    }
  
  cout << endl;
}

/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: gift1
*/
#include <bits/stdc++.h>
using namespace std;

struct ppl{
  string name;
  int m;
} gift[11];

int main() {
  freopen("gift1.in", "r", stdin);
  freopen("gift1.out", "w", stdout);

  int np;
  cin>>np;
  for(int i = 0; i < np; i++) {
    cin>>gift[i].name;
  }

  for(int i = 0; i < np; i++) {
    string name;
    int n, money;
    cin>>name;
    cin>>money>>n;
    int mark = 0;
    for(int j = 0; j < np; j++) {
      if(gift[j].name == name) {
        mark = j;
      }
    }
    for(int j = 0; j < n; j++) {
      string name2;
      cin>>name2;
      for(int k = 0; j < np; k++) {
        if (gift[k].name == name2) {
          gift[k].m += money/n;
          gift[mark].m -= money/n;
          break;
        }
      }
    }
  }

  for(int i = 0; i < np; i++) {
    cout<<gift[i].name<<" "<<gift[i].m<<endl;
  }
} 

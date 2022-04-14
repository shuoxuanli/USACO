#include <bits/stdc++.h>
using namespace std;

const int maxN =  1e5 + 1;
int p1[maxN], p2[maxN], p3[maxN];

int main() {

  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);
  
  int n, q;
  cin>>n>>q;

  for(int i = 1; i <= n; i++) {
    int cow;
    cin>>cow;

    p1[i] = p1[i-1];
    p2[i] = p2[i-1];
    p3[i] = p3[i-1];

    if(cow == 1) {
      p1[i]++;
    }
    else if(cow == 2) {
      p2[i]++;
    } else {
      p3[i]++;
    }
  }

  for(int i = 0; i < q; i++) {
    int a, b;
    cin>>a>>b;

    int h = p1[b] - p1[a-1];
    int g = p2[b] - p2[a-1];
    int j = p3[b] - p3[a-1];
    cout<<h<<" "<<g<<" "<<j<<endl;
  }
} 

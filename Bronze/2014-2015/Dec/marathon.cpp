#include <bits/stdc++.h>
using namespace std;

int loc[100001][2], dis[100001], dis2[100001];

int main() {
  ifstream fin ("marathon.in");
  ofstream fout ("marathon.out");

  int n;
  fin>>n;

  for(int i = 0; i < n; i++) {
    fin>>loc[i][0]>>loc[i][1];
  } 

  for(int i = 1; i < n; i++) {
    dis[i] = dis[i-1] + abs(loc[i-1][0]-loc[i][0]) + abs(loc[i-1][1]-loc[i][1]);
    if(i != n-1) {
      dis2[i] = abs(loc[i-1][0]-loc[i+1][0]) + abs(loc[i-1][1]-loc[i+1][1]);
    }
  }

  int ans = INT_MAX;
  for(int i = 1; i < n-1; i++) {
    int curr = dis[i-1] + dis2[i] + (dis[n-1] - dis[i+1]);
    ans = min(curr, ans);
  }

  fout<<ans<<'\n';
  return 0;
} 

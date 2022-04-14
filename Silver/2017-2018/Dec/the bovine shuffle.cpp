#include <bits/stdc++.h>
using namespace std;

int nxt[100001], inDegree[100001], cnt = 0, n;

void bfs() {
  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(inDegree[i] == 0) {
      q.push(i);
      cnt++;
    }
  }

  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    inDegree[nxt[cur]]--;
    if(inDegree[nxt[cur]] == 0) {
      q.push(nxt[cur]);
      cnt++;
    }
  }
}

int main() {
  ifstream cin("shuffle.in");
  ofstream cout("shuffle.out");

  cin>>n;
  for(int i = 1; i <= n; i++) {
    cin>>nxt[i];
    inDegree[nxt[i]]++;
  }

  bfs();

  cout<<n-cnt<<endl;
} 

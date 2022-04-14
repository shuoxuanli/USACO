#include<bits/stdc++.h>
using namespace std;

int pos[101], passTo[100];

int getTarget(int i, int n) {
  if(i == 0) {
    return 1;
  }
  if(i == n-1) {
    return n-2;
  }
  if(pos[i] - pos[i-1]<= pos[i+1] - pos[i]) {
    return i-1;
  } else {
    return i+1;
  }
}

int main() {

  freopen("hoofball.in", "r", stdin);
  freopen("hoofball.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>pos[i];
  }

  sort(pos, pos+n);

  for(int i = 0; i < n; i++) {
    passTo[getTarget(i,n)]++;
  }

  int ball = 0;
  for(int i = 0; i < n; i++) {
    if(passTo[i] == 0) {
      ball++;
    } else if(passTo[i] == 1 && passTo[i+1] == 1 && getTarget(i,n) == i+1 && getTarget(i+1, n) == i) {
      ball++;
    }
  }

  cout<<ball<<endl;
  return 0;
} 

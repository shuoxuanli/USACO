#include <bits/stdc++.h>
using namespace std;

int canvas[11][11];
int n;

bool present(int c) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(c == canvas[i][j]) {
        return true;
      }
    }
  }
  return false;
}

bool interfere(int c1, int c2) {
  int left = INT_MAX, right = 0;
  int top = INT_MAX, bottom = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(canvas[i][j] == c2) {
        left = min(j, left);
        right = max(j, right);
        top = min(i, top);
        bottom = max(i, bottom);
      }
    }
  }

  for(int i = top; i <= bottom; i++) {
    for(int j = left; j <= right; j++) {
      if(canvas[i][j] == c1) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  freopen("art.in", "r", stdin);
  freopen("art.out", "w", stdout);

  cin>>n;

  for(int i = 0; i < n; i++) {
    string s;
    cin>>s;
    for(int j = 0; j < n; j++) {
      canvas[i][j] = s[j] - '0';
    }
  }

  int ans = 0;
  for(int i = 1; i <= 9; i++) {
    if(present(i)) {
      bool found = true;
      for(int j = 1; j <= 9; j++) {
        if(present(j) && j != i && interfere(i, j)) {
          found = false;
          break;
        }
      }
      if(found) {
        ans++;
      }
    }
  }

  cout<<ans<<endl;
  return 0;
} 

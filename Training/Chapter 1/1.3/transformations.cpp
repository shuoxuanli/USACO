/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: transform
*/

#include<bits/stdc++.h>
using namespace std;

int n;
char org[11][11], tiles[11][11], transformed[11][11];

void flip() {
  for(int i = 0; i < n; i++) {
    for(int  j = 0; j < n/2; j++) {
      swap(tiles[i][j], tiles[i][n-1-j]);
    }
  }
}

void clockwise90() {
  char temp[11][11];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      temp[i][j] = tiles[n-1-j][i];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      tiles[i][j] = temp[i][j];
    }
  }
}

bool check() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(tiles[i][j] != transformed[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  freopen("transform.in", "r", stdin);
  freopen("transform.out", "w", stdout);

  cin>>n;

  for(int i = 0; i < n; i++) {
    string s;
    cin>>s;
    for(int j = 0; j < n; j++) {
      tiles[i][j] = s[j];
      org[i][j] = s[j];
    }
  }

  for(int i = 0; i < n; i++) {
    string s;
    cin>>s;
    for(int j = 0; j < n; j++) {
      transformed[i][j] = s[j];
    }
  }
  

  int count = 0;
  for(int i = 0; i < 3; i++) {
    count++;
    clockwise90();
    if(check()) {
      cout<<count<<endl;
      return 0;
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      tiles[i][j] = org[i][j];
    }
  }

  flip();
  if(check()) {
    cout<<4<<endl;
    return 0;
  } else {
    for(int i = 0; i < 3; i++) {
      clockwise90();
      if(check()) {
        cout<<5<<endl;
        return 0;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      tiles[i][j] = org[i][j];
    }
  }

  if(check()) {
    cout<<6<<endl;
    return 0;
  }

  cout<<7<<endl;
  return 0;
} 

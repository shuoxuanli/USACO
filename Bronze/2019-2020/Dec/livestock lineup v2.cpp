#include<bits/stdc++.h>
using namespace std;

string a[8], b[8], answers[8];

int n;
string cows[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy","Blue", "Buttercup", "Sue"};

int getIndex(string str, int len) {
  for(int i = 0; i < len; i++) {
    if(str == answers[i]) {
      return i;
    }
  }
  return -1;
}

bool canPlace(string name, int len) {
  if(getIndex (name, len)!= -1) {
    return false;
  }

  int nb = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == name && getIndex(b[i], len) == -1) {
      nb++;
    }
    if(b[i] == name && getIndex(a[i], len) == -1) {
      nb++;
    }

    if(nb == 2) return false;
  }

  if(len > 0) {
    string lc = answers[len-1];
    for(int i = 0; i < n; i++) {
      if(a[i] == lc && getIndex(b[i], len) == -1 && b[i] != name) {
        return false;
      }
      if(b[i] == lc && getIndex(a[i], len) == -1 && a[i] != name) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);
  cin>>n;

  for(int i = 0; i < n; i++) {
    string temp, c1, c2;
    cin>>a[i];
    cin>>temp;
    cin>>temp;
    cin>>temp;
    cin>>temp;
    cin>>b[i];
  }
  
  for(int i = 0; i < 8; i++) {
    int current = 0;
    while(!canPlace(cows[current], i)) {
      current++;
    }
    answers[i] = cows[current];
    cout<<answers[i]<<endl;
  }
  return 0;
} 

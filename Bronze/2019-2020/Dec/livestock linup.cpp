#include<bits/stdc++.h>
using namespace std;

string a[8], b[8];

string cows[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy","Blue", "Buttercup", "Sue"};

int getIndex(string str) {
  for(int i = 0; i < 8; i++) {
    if(cows[i] == str) {
      return i;
    }
  }
  return 0;
}

int main() {
  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);

  int n;
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

  do {
    bool found = true;
    for(int i = 0; i < n; i++) {
      if(abs(getIndex(a[i]) - getIndex(b[i])) == 1) {
        continue;
      } else{
        found = false;
        break;
      }
    }
    if(found) {
      for(int i = 0; i < 8; i++) {
        cout<<cows[i]<<endl;
      }
      return 0;
    }
  } while(next_permutation(cows, cows + 8));
}

#include<bits/stdc++.h>
using namespace std;

struct cow{
  string name;
  int milk = 0;
};

cow c[7];

bool cmp(cow a, cow b) {
  return a.milk > b.milk;
}

int main() {
  freopen("notlast.in", "r", stdin);
  freopen("notlast.out", "w", stdout);
  
  int n;
  cin>>n;

  string name[] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

  for(int i = 0; i < 7; i++) {
    c[i].name = name[i];
  }

  for(int i = 0; i < n; i++) {
    string str = "";
    int num;
    cin>>str>>num;
    for(int j = 0; j < 7; j++) {
      if(c[j].name == str) {
        c[j].milk += num;
      }
    }
  }

  sort(c, c+n, cmp);

  int min = c[6].milk;
  int ans = 0;
  int cnt = 0;
  for(int i = 6; i >= 0; i--) {
    if(c[i].milk != min) {
      ans = i;
      break;
    }
    else {
      cnt++;
    }
  }

  int count = 0; 
  for(int i = 0; i < 7; i++) {
    if(c[i].milk == c[ans].milk) {
      count++;
    }
  }
  
  if(count > 1 || cnt == 7) {
    cout<<"Tie"<<endl;
  } else {
    cout<<c[ans].name<<endl;
  } 
  return 0;
} 

/*
 ID: shuoxua2
 PROG:lamps
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int n, c;
set<int> on, off;
vector<pair<string, int>> s;
set<string> ans;

string one(string t) {
  for(int i = 0; i < n; i++) {
    t[i] = (t[i]=='0') ? '1':'0';
  }
  return t;
}

string two(string t) {
  for(int i = 0; i < n; i+=2) {
    t[i] = (t[i]=='0') ? '1':'0';
  }
  return t;
}

string three(string t) {
  for(int i = 1; i < n; i+=2) {
    t[i] = (t[i]=='0') ? '1':'0';
  }
  return t;
}

string four(string t) {
  for(int i = 0; 3*i < n; i++) {
    t[3*i] = (t[3*i]=='0') ? '1':'0';
  }
  return t;
}

void permute() {
  for(int i = 0; i < (1<<4); i++) {
    string str = "";
    int cnt = 0;
    for(int i = 0; i < n; i++) str += "1";

    if(i&1) {
      str = one(str);
      cnt++;
    }
    if(i&2) {
      str = two(str);
      cnt++;
    }
    if(i&4) {
      str = three(str);
      cnt++;
    }
    if(i&8) {
      str = four(str);
      cnt++;
    }

    s.push_back({str, cnt});
  }
}

int main() {
  ifstream cin("lamps.in");
  ofstream cout("lamps.out");
  
  cin>>n>>c;

  int m;
  while(cin>>m && m != -1) {
    on.insert(m);
  }

  while(cin>>m && m != -1) {
    off.insert(m);
  }
  
  permute();

  for(auto& m : s) {
    if(c >= m.second && ((c-m.second)%2==0 || (c-m.second)%3==0)) {
      bool b = 1; string t = m.first;
      for(int i = 0; i < n; i++) {
        if(on.count(i+1) && t[i] == '0') b = 0;
        if(off.count(i+1) && t[i] == '1') b = 0;
      }
      if(b) {
        ans.insert(t);
      }
    }
  }

  if(ans.size()) for(string s : ans) cout<<s<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
  
  return 0;
} 

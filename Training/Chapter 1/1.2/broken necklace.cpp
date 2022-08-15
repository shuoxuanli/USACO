/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: beads
*/
#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int l(string left) {
  int w = 0, r = 0, b = 0;
  int ans = 0;
  bool inter = false;
  for(int i = left.length()-1; i >= 0; i--) {
    if(left[i] == 'w' && r== 0 && b == 0) {
      w++;
    }
    else if(left[i] == 'w' && r > 0 && b == 0) {
      r++;
    }
    else if(left[i] == 'w' && b > 0 && r == 0) {
      b++;
    }
    else if(left[i] == 'r') {
      r++;
    }
    else if(left[i] == 'b') {
      b++;
    }

    int temp= 0;
    if(r > 0 && b > 0 && r > b) {
      temp = r + w;
      ans = max(temp, ans);
      r = 0;
      w = 0;
      inter = true;
      break;
    }
    else if(r > 0 && b > 0 && r < b) {
      temp = b + w;
      ans = max(temp, ans);
      b = 0;
      w = 0;
      inter = true;
      break;
    }
    else if(r == b) {
      if(left[i] == 'r') {
        temp = b;
      } else {
        temp = r;
      }
      ans = max(temp, ans);
      break;
    }
  }
  if(!inter) {
    if(r > b) {
      ans = r+w;
    } else {
      ans = b+w;
    }
  }
  return ans;
}

int r(string right) {
  int w = 0, r = 0, b = 0;
  int ans = 0;
  bool inter = false;
  for(int i = 0; i < right.length(); i++) {
    if(right[i] == 'w' && r== 0 && b == 0) {
      w++;
    }
    else if(right[i] == 'w' && r > 0 && b == 0) {
      r++;
    }
    else if(right[i] == 'w' && b > 0 && r == 0) {
      b++;
    }
    else if(right[i] == 'r') {
      r++;
    }
    else if(right[i] == 'b') {
      b++;
    }

    int temp = 0;
    if(r > 0 && b > 0 && r > b) {
      temp = r + w;
      ans = max(temp, ans);
      r = 0; 
      w = 0;
      inter = true;
      break;
    }
    else if(r > 0 && b > 0 && r < b) {
      temp = b + w;
      ans = max(temp, ans);
      b = 0; 
      w = 0;
      inter = true;
      break;
    } 
    else if(r > 0 && b > 0 && r == b) {
      if(right[i] == 'r') {
        temp = b;
      } else {
        temp = r;
      }
      ans = max(temp, ans);
      break;
    }
  }
  if(!inter) {
      if(r > b) {
        ans = r+w;
      } else {
        ans = b+w;
      }
    }
  return ans;
}

int main() {
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);

  cin>>n;
  cin>>s;
  
  int ans = 0;
  for(int i = 1; i < n; i++) {
    string left = s.substr(i, n-i) + s.substr(0,i);
    string right = s.substr(i, n-i) + s.substr(0,i);
    int temp = l(left) + r(right);
    ans = max(temp, ans);
  }
  
  if(ans > n) {
   ans = n;
  }
  cout<<ans<<endl;
  return 0;
}

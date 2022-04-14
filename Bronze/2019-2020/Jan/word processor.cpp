#include<bits/stdc++.h>
using namespace std;

int main() {

  freopen("word.in", "r", stdin);
  freopen("word.out", "w", stdout); 

  int n, k;
  cin>>n>>k;
  
  int count = 0;
  for(int i = 0; i < n; i++) {
    string word;
    cin>>word;
    if(word.length()+count <= k) {
      if(i == 0) {
        cout<<word;
      } else{
        cout<<" "<<word;
      }
      count+=word.length();
    }
    else {
      cout<<endl;
      cout<<word;
      count = word.length();
    }
  }
  return 0;
} 

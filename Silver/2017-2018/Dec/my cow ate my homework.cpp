#include <bits/stdc++.h>
using namespace std;


int homework[100001], suffix[100001], m[100001];

int main() {
  ifstream cin("homework.in");
  ofstream cout("homework.out");

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>homework[i];
  }


  for(int i = 0; i <= n; i++) {
    m[i] = INT_MAX;
  }
  
  for(int i = n-1; i >= 0; i--) {
    suffix[i] = homework[i] + suffix[i+1];
    m[i] = min(homework[i], m[i+1]);
  }
  
  double score = 0;
  for(int i = 1; i < n-1; i++) {
    double cur = (double)(suffix[i]-m[i])/(n-i-1);
    score = max(score, cur);
  }


  for(int i = 1; i < n-1; i++) {
    double cur = (double)(suffix[i]-m[i])/(n-i-1);
    if(cur == score) {
      cout<<i<<endl;
    }
  }

  return 0;
} 

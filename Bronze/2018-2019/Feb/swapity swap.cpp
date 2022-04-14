#include<bits/stdc++.h>
using namespace std;

int cows[101];

void reversed(int start, int end) {
  while(start < end) {
    swap(cows[start-1], cows[end-1]);
    start++;
    end--;
  }
}

bool sorted(int nums[], int n) {
  for(int i = 0; i < n; i++) {
    if(nums[i] != i+1) {
      return false;
    }
  }
  return true;
}

int main() {
  freopen("swap.in", "r", stdin);
  freopen("swap.out", "w", stdout);

  int n, k, a1, a2, b1, b2;
  cin>>n>>k;
  cin>>a1>>a2;
  cin>>b1>>b2;

  for(int i = 0; i < n; i++) {
    cows[i] = i+1;
  }
  
  int count = 1;
  reversed(a1, a2);
  reversed(b1, b2);

  while(!sorted(cows, n)) {
    reversed(a1, a2);
    reversed(b1, b2);
    count++;
  }

  k%=count;

  for(int i = 0; i < k; i++) {
    reversed(a1, a2);
    reversed(b1, b2);
  }

  for(int i = 0; i < n; i++) {
    cout<<cows[i]<<endl;
  }

  return 0;
} 

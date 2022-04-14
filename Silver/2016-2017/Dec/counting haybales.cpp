#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
int prefix[maxN], pos[maxN];

int main() {
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);
  
  int n, q;
  cin>>n>>q;

  for(int i = 1; i <= n; i++) {
    cin>>pos[i];
  }

  sort(pos + 1, pos + n + 1);

  for(int i = 1; i <= n; i++) {
    prefix[i] = i;
  }

  for(int i = 0; i < q; i++) {
    int a, b;
    cin>>a>>b;

    bool fit = false;
    int l = 1, r = n;
    while(l <= r) {
      int mid = (l+r)/2;
      if(a == pos[mid]) {
        r = mid;
        fit = true;
        break;
      }
      else if(a < pos[mid]) {
        r = mid-1;
      }
      else if(a > pos[mid]) {
        l = mid+1;
      }
    }

    int start = r;

    l = 1, r = n;
    while(l <= r) {
      int mid = (l+r)/2;
      if(b == pos[mid]) {
        r = mid;
        break;
      }
      else if(b < pos[mid]) {
        r = mid-1;
      }
      else if(b > pos[mid]) {
        l = mid+1;
      }
    }

    int end = r;

    if(fit) {
      cout<<prefix[end] - prefix[start-1]<<endl;
    } else {
      cout<<prefix[end] - prefix[start]<<endl;;
    }
  }

  return 0;
} 

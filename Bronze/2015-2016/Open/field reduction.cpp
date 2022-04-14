#include <bits/stdc++.h>
using namespace std;

struct coor{
  int x, y;
};

coor pt[50001];

bool cmpx(coor a, coor b) {
  return a.x > b.x;
}

bool cmpy(coor a, coor b) {
  return a.y > b.y;
}

int main() {
  freopen("reduce.in", "r", stdin);
  freopen("reduce.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>pt[i].x>>pt[i].y;
  }

  sort(pt, pt+n, cmpx);

  int left = INT_MAX, right = 0;
  int top = 0, bottom = INT_MAX;
  for(int i = 1; i < n; i++) {
    left = min(pt[i].x, left);
    right = max(pt[i].x, right);
    top = max(pt[i].y, top);
    bottom = min(pt[i].y, bottom);
  }
  
  int area = abs(right-left)*abs(top-bottom);

  left = INT_MAX, right = 0;
  top = 0, bottom = INT_MAX;
  for(int i = 0; i < n-1; i++) {
    left = min(pt[i].x, left);
    right = max(pt[i].x, right);
    top = max(pt[i].y, top);
    bottom = min(pt[i].y, bottom);
  }
  area = min(abs(right-left)*abs(top-bottom), area);

  sort(pt, pt+n, cmpy);

  left = INT_MAX, right = 0;
  top = 0, bottom = INT_MAX;
  for(int i = 1; i < n; i++) {
    left = min(pt[i].x, left);
    right = max(pt[i].x, right);
    top = max(pt[i].y, top);
    bottom = min(pt[i].y, bottom);
  }

  area = min(abs(right-left)*abs(top-bottom), area);

  left = INT_MAX, right = 0;
  top = 0, bottom = INT_MAX;
  for(int i = 0; i < n-1; i++) {
    left = min(pt[i].x, left);
    right = max(pt[i].x, right);
    top = max(pt[i].y, top);
    bottom = min(pt[i].y, bottom);
  }

  area = min(abs(right-left)*abs(top-bottom), area);

  cout<<area<<endl;
  return 0;
} 

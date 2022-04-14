#include<bits/stdc++.h>
using namespace std;

int pastures[1001][1001];
int com[1001][1001];

bool valid(int x, int y) {
  if(x>=0 && x<=1000 && y >= 0 && y <=1000) {
    return true;
  }
  return false;
}

int comfort(int x, int y) {
  int cnt = 0;

  if(valid(x+1, y) && pastures[x+1][y] == 1) {
    cnt++;
  }
  if(valid(x-1, y) && pastures[x-1][y] == 1) {
    cnt++;
  }
  if(valid(x, y+1) && pastures[x][y+1] == 1) {
    cnt++;
  }
  if(valid(x, y-1) && pastures[x][y-1] == 1) {
    cnt++;
  }

  if(cnt==3) {
    com[x][y] = 1;
    return 1;
  }
  return 0;
}


int before(int x, int y) {
  int cnt = 0;

  if(valid(x+1, y) && com[x+1][y] == 1) {
    cnt++;
    com[x+1][y] = 0;
  }
  if(valid(x-1, y) && com[x-1][y] == 1) {
    cnt++;
    com[x-1][y] = 0;
  }
  if(valid(x, y+1) && com[x][y+1] == 1) {
    cnt++;
    com[x][y+1] = 0;
  }
  if(valid(x, y-1) && com[x][y-1] == 1) {
    cnt++;
    com[x][y-1] = 0;
  }

  return cnt;
}

int after(int x, int y) {
  int cnt = 0;

  if(valid(x+1, y) && pastures[x+1][y] == 1 && comfort(x+1, y)) {
    cnt++;
  }
  if(valid(x-1, y) && pastures[x-1][y] == 1 && comfort(x-1, y)) {
    cnt++;
  }
  if(valid(x, y+1) && pastures[x][y+1] == 1 && comfort(x, y+1)) {
    cnt++;
  }
  if(valid(x, y-1) && pastures[x][y-1] == 1 && comfort(x, y-1)) {
    cnt++;
  }

  return cnt;
}

int main() {
  int n;
  cin>>n;
  int ans = 0;
  for(int i = 0;i < n; i++) {
    int x, y;
    cin>>x>>y;

    ans -= before(x,y);
    pastures[x][y] = 1;
    ans += comfort(x,y);
    ans += after(x,y);
    cout<<ans<<endl;
  }

  return 0;
} 

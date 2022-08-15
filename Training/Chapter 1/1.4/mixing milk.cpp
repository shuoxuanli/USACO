/*
ID: Shuoxuan Li [shuoxua2]
LANG: C++
TASK: milk
*/
#include<bits/stdc++.h>
using namespace std;

struct farmer{
  int price, unit;
};

farmer milk[5001];

bool cmp(farmer a, farmer b) {
  return a.price < b.price;
}
int main() {
  freopen("milk.in", "r", stdin);
  freopen("milk.out", "w", stdout);

  int n, m;
  cin>>n>>m;

  int money = 0;
  for(int i = 0; i < m; i++) {
    cin>>milk[i].price>>milk[i].unit;
  }

  sort(milk, milk + m, cmp);

  for(int i = 0; i < m; i++) {
    if(n > milk[i].unit) {
      n -= milk[i].unit;
      money += milk[i].price * milk[i].unit;
    }
    else {
      money += n*milk[i].price;
      break;
    }
  }

  cout<<money<<endl;
  return 0;
} 

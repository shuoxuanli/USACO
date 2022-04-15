#include <bits/stdc++.h>
using namespace std;
set<int> s;
int num[100010];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
      int year;
      cin>>year;
      year /= 12;
      year++;
      s.insert(year);
  }

  vector<int> diff;
  int last = 0, ans = s.size()*12;
  for(int num : s) {
    diff.push_back(num-last-1);
    last = num;
  }

  sort(diff.begin(), diff.end());
  for(int i = 0; i <= diff.size() - k; i++) {
    ans += 12*diff[i];
  }

  cout << ans << endl;
}

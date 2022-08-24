#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)(x.size())

int n, mn[100005], mx[100005];
pair<int, int> a[100005];

int main() {
   ifstream cin("moop.in");
   ofstream cout("moop.out");
   cin>>n;
   for(int i = 0; i < n; i++)
      cin>>a[i].first>>a[i].second;
   sort(a, a+n);
   for(int i = 0; i < n; i++) 
      mn[i] = (i == 0 ? a[i].second : min(mn[i-1], a[i].second));
   for(int i = n-1; i >= 0; i--)
      mx[i] = (i == n-1 ? a[i].second : max(mx[i+1], a[i].second));
   int ans = 1;
   for(int i = 0; i < n-1; i++) 
      ans += (mn[i] > mx[i+1]);
   cout<<ans<<endl; 
   return 0;
}

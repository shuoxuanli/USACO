#include<bits/stdc++.h>
using namespace std;

struct Entry {
  int index;
  int value;
};

Entry entries[100000];

int main() {
  ifstream cin("sort.in");
  ofstream cout("sort.out");
  
  int n;
  cin>>n;

  for (int i = 0; i < n; i++) {
    entries[i].index = i;
    cin>>entries[i].value;
  }

  sort(entries, entries + n, [](Entry a, Entry b) {
    return a.value < b.value || (a.value == b.value && a.index < b.index);
  });

  int answer = 0;
  for (int j = 0; j < n; j++) {
    answer = max(answer, entries[j].index - j);
  }

  cout<<answer+1<<endl;
}

#include <bits/stdc++.h>
using namespace std;

int m, n, k, folders[100001], freqs[10001];
set<int> emails;

string solve() {
  int l = 1, r = k, nxt = k;
  stack<int> stk;
  bool end = false;
  while(!end) {
    end = true;
    if(emails.size() <= k && stk.empty()) {
      return "YES";
    } 
    if(r == m) {
      return "YES";
    }
    
    int cnt = 0;
    set<int> :: iterator iter;
    vector<int> v;
    for(iter = emails.begin(); iter != emails.end(); iter++) {
      if(cnt >= k) {
        break;
      }
      if(folders[*iter] >= l && folders[*iter] <= r) {
        freqs[folders[*iter]]--;
        v.push_back(*iter);
      }
      cnt++;
    }

    for(int n : v) {
      emails.erase(n);
    }
    
    int efill = v.size();
    while(efill > 0 && nxt < n) {
     if(folders[nxt+1] >= l && folders[nxt+1] <= r) {
       freqs[folders[nxt+1]]--;
       emails.erase(nxt+1);
      } else {
       efill--;
      }
      end = false;
      nxt++;
    }
    
    int ffill = k-emails.size();
    while(ffill > 0 && nxt == n && !stk.empty()) {
      if(folders[stk.top()] >= l && folders[stk.top()] <= r) {
        freqs[folders[stk.top()]]--;
      } else {
        emails.insert(stk.top());
        ffill--;
      }
      stk.pop();
      end = false;
    }
    
    if(freqs[l] == 0) {
      l++;
      r++;
      end = false;
    } else {
      while(nxt < n) {
        end = false;
        if(folders[nxt] >= l && folders[nxt] <= r) {
          if(folders[nxt] == l) {
            break;
          }
          freqs[folders[nxt]]--;
          emails.erase(nxt);
        } else {
          stk.push(*emails.begin());
          emails.erase(emails.begin());
        }
        nxt++;
      }
    }
  }
  return "NO";
}

int main() {
  int t;
  cin>>t;
  
  while(t--) {
    cin>>m>>n>>k;

    for(int i = 1; i <= n; i++) {
      int f; cin>>f;
      folders[i] = f;
      freqs[f]++;
      emails.insert(i);
    }
    
    cout<<solve()<<endl;
    emails.clear();
    memset(freqs, 0, sizeof(freqs));
  }

  return 0;
} 

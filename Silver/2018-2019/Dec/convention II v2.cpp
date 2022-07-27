#include <bits/stdc++.h>
using namespace std;

struct cow {
  int arrive, t, prior;
};

cow cows[100001];

bool cmp(const cow &c1, const cow &c2) {
  if (c1.arrive != c2.arrive) {
    return c1.arrive < c2.arrive;
  }
  return c1.prior < c2.prior; 
}

struct cmpPrior {
	bool operator() (cow a, cow b) {
    return a.prior > b.prior;
  }
};

priority_queue<cow, vector<cow> , cmpPrior> pq; //todo 

int main() {
  freopen("convention2.in","r",stdin);
  freopen("convention2.out","w",stdout);
  
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    int a, t;
    scanf("%d%d", &a, &t);
    cows[i]= {a, t, i};
  }
  sort(cows, cows+n, cmp);
  int last=cows[0].arrive; 
  int answer=0;
  int added=1;

  pq.push(cows[0]);

  while(pq.size()>0) {
    cow c = pq.top();
    pq.pop();
    int wait = max(0, last - c.arrive);
    int tot = wait + c.arrive + c.t;
    last = tot;
    answer = max(wait, answer);
    for(int i = added; i < n; i++) {
      if(tot >= cows[i].arrive) {
        pq.push(cows[i]);
        added++;
      } else {
        break;
      }
    }

    if(pq.size() == 0 && added < n) {
      pq.push(cows[added]);
      added++;
    }
  }

  cout<<answer<<endl;
  return 0;
}

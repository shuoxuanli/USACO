#include <bits/stdc++.h>
using namespace std;

struct edge {
	int a, b, w;
};

struct query {
	int v, w, id;
};

int f[100001], sum[100001];
edge edges[100001];
query queries[100001];
int ans[100001];

int find(int a) {
	if (f[a] == a) {
		return a;
	}
	return f[a] = find(f[a]);
} 

void merge(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);
	if(f1 != f2) {
		f[f2] = f1;
		sum[f1] += sum[f2];
	}
}

bool cmpEdge(const edge &a, const edge &b) {
	return a.w > b.w;
}

bool cmpQuery(const query &a, const query &b) {
	return a.w > b.w;
}

int main() {
  ifstream cin("mootube.in");
  ofstream cout("mootube.out");
  
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, q;
  cin>>n>>q;
  
  for(int i=0; i<n-1; i++) {
    int x, y, w;
    cin>>x>>y>>w;
    x--;
    y--;
    edges[i]={x, y, w};
	}
	
	sort(edges, edges+n-1, cmpEdge);
	
	for(int i=0; i<n; i++) {
    f[i] = i;
    sum[i] = 1;
	}
    
  for(int i=0; i<q; i++) {
    int k, v;
    cin>>k>>v;
    v--;
    queries[i] = {v, k, i};
	}

	sort(queries, queries+q, cmpQuery);

	int idx=0;
	for(int i=0; i<q; i++) {
		while(idx<n-1 && edges[idx].w >= queries[i].w) {
			merge(edges[idx].a, edges[idx].b);
			idx++;
		}
		ans[queries[i].id] = sum[find(queries[i].v)] - 1;
	}

	for(int i=0; i<q; i++) {
		cout<<ans[i]<<endl;
	}

  return 0;
}

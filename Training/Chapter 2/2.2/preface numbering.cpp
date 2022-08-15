/*
 ID: shuoxua2
 PROG: preface
 LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int n;
char s[10]="IVXLCDM";
int num[15]={0,1,2,3,1,0,1,2,3,1,0};
int ans[10];

void cnt(int n){
  int i=0;
  while(n){
    int t = n%10;
    n/=10;
    ans[i] += num[t];
    if(t >= 4 && t < 9) ans[i+1]++;
    if(t==9) ans[i+2]++;
    i+=2;
  }
}

int main(){
  freopen("preface.in","r",stdin);
  freopen("preface.out","w",stdout);
  cin>>n;

  for(int i=1;i<=n;i++)    
    cnt(i);
  for(int i=0;s[i];i++)if(ans[i])
    cout<<s[i]<<" "<<ans[i]<<endl;
  return 0;
}    

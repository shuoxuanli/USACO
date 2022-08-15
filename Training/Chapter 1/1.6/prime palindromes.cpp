/*
ID: shuoxua2
LANG: C++
TASK: pprime
*/
#include<bits/stdc++.h>
using namespace std;

int a,b;
vector<int> ans;

bool isprime(int a){
  int i;
  for (i=2;i<=sqrt(a);i++) if (a%i==0) return 0;
  return 1;
}

int digit(int a){ 
  int i;
  for (i=0;a!=0;i++) a/=10;
  return i-1;
}

void gpal(char s[],int nowdigit,int digit){ 
  int i,sum=0;
  if (nowdigit==digit/2+1){
    for (i=0;i<=digit/2;i++) s[digit-i]=s[i];
    for (i=0;i<=digit;i++) sum=sum*10+s[i];
    if (sum>=a && sum<=b && isprime(sum)) ans.push_back(sum);
  }
  else for (i=0;i<=9;i++){
    s[nowdigit]=i; 
    gpal(s,nowdigit+1,digit);
  }
}

int main(){
  ifstream cin("pprime.in");
  ofstream cout("pprime.out");
  int i;
  char k[20];
  cin>>a>>b;
  if (a%2==0) a++;
  if (b%2==0) b--;
  for (i=digit(a);i<=digit(b);i++) gpal(k,0,i);
  for(int v : ans) cout<<v<<endl;
  return 0;
}

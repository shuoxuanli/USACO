#include<bits/stdc++.h>
using namespace std;

string zodiacs[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog"
, "Pig", "Rat"};

struct cow {
  string name, yr;
  int age;
};

cow zod[110];

int getCow(string s) {
  for(int i = 0; i < 101; i++) {
    if(zod[i].name == s) {
      return i;
      break;
    }
  }
  return 0;
}

int getYear(string s) {
  for(int i = 0; i < 12; i++) {
    if(s == zodiacs[i]) {
      return i;
    }
  }
  return 0;
}

int main() {
  int n;
  cin>>n;

  zod[0].name = "Bessie";
  zod[0].age = 0;
  zod[0].yr = "Cow";

  for(int i = 1; i <= n; i++) {
    string temp, pn, year, pre;
    cin>>zod[i].name;
    cin>>temp;
    cin>>temp;
    cin>>pn;
    cin>>zod[i].yr;
    cin>>temp;
    cin>>temp;
    cin>>pre;
    
    if(pn == "previous") {
      if(getYear(zod[i].yr) < getYear(zod[getCow(pre)].yr)) {
        zod[i].age = zod[getCow(pre)].age;
        zod[i].age -= abs(getYear(zod[i].yr) - getYear(zod[getCow(pre)].yr));
      }
      else if(getYear(zod[i].yr) >= getYear(zod[getCow(pre)].yr)) {
        zod[i].age = zod[getCow(pre)].age;
        zod[i].age -= 12 - abs(getYear(zod[i].yr) - getYear(zod[getCow(pre)].yr));
      }
    }
    else if(pn == "next") {
      if(getYear(zod[i].yr) <= getYear(zod[getCow(pre)].yr)) {
        zod[i].age = zod[getCow(pre)].age;
        zod[i].age += 12 - abs(getYear(zod[i].yr) - getYear(zod[getCow(pre)].yr));
      }
      else if(getYear(zod[i].yr) > getYear(zod[getCow(pre)].yr)) {
        zod[i].age = zod[getCow(pre)].age;
        zod[i].age += abs(getYear(zod[i].yr) - getYear(zod[getCow(pre)].yr));
      }
    }

    if (zod[i].name == "Elsie") {
      cout<<abs(zod[i].age)<<endl;
      break;
    }
  }
  
  return 0;
} 

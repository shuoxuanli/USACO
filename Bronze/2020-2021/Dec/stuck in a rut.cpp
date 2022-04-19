#include <bits/stdc++.h>
using namespace std;

struct Cow {
  int x, y;
  int len;
  int sequence;
};

bool cmpByX(Cow a, Cow b){ 
  return a.x < b.x;
}

bool cmpByY(Cow a, Cow b){ 
  return a.y < b.y;
}

bool cmpBySequence(Cow a, Cow b){ 
  return a.sequence < b.sequence;
}

Cow cowEast[50];
Cow cowNorth[50];
char sequence[50];

int main(){
  int n;
  cin>>n;

  int eastCowCnt = 0, northCowCnt = 0;
  for(int i = 0; i < n; i++){
    char faceTo;
    int x, y;
    cin>>faceTo>>x>>y;
    if(faceTo == 'E'){
      Cow cow;
      cow.x = x;
      cow.y = y;
      cow.len = INT_MAX;
      cow.sequence = i;
      cowEast[eastCowCnt++] = cow;
    }else {
      Cow cow;
      cow.x = x;
      cow.y = y;
      cow.len = INT_MAX;
      cow.sequence = i;
      cowNorth[northCowCnt++] = cow;
    }
    sequence[i] = faceTo;
  }

  sort(cowEast, cowEast+eastCowCnt, cmpByY);
  sort(cowNorth, cowNorth+northCowCnt, cmpByX);

  for(int i = 0; i < eastCowCnt; i++){
    for(int j = 0; j < northCowCnt; j++){
      if(cowEast[i].len != INT_MAX || cowNorth[j].len != INT_MAX){ 
	continue;
      }
      int lenX = cowNorth[j].x - cowEast[i].x;
      int lenY = cowEast[i].y - cowNorth[j].y;

      if(lenY == lenX || lenX < 0 || lenY < 0){
	continue;
      }

      if(lenX < lenY){
	cowNorth[j].len = lenY;
      } else {
	cowEast[i].len = lenX;
      }
    }
  }

  sort(cowEast, cowEast + eastCowCnt, cmpBySequence);
  sort(cowNorth, cowNorth + northCowCnt, cmpBySequence);

  int eastIndex = 0, northIndex = 0;
  for(int i = 0; i < n; i++){
    if(sequence[i]=='E'){
      if(cowEast[eastIndex].len == INT_MAX){
	cout<<"Infinity"<<endl;
      } else{
	cout<<cowEast[eastIndex].len<<endl;
      }
      eastIndex++;
    } else {
      if(cowNorth[northIndex].len == INT_MAX){
        out<<"Infinity"<<endl;
      } else{
	cout<<cowNorth[northIndex].len<<endl;
      }
      northIndex++;
    }
  }
  return 0;
}

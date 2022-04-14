#include <bits/stdc++.h>
using namespace std;


char pastures[1002][1002]; 
int cowTo[1002][1002]; 

int getAdjacentCows(int x, int y){
    int result = 0;
	if(pastures[x-1][y] == 'C'){ 
		result++;
	}
	if(pastures[x+1][y] == 'C'){ 
		result++;
	}
	if(pastures[x][y-1] == 'C'){ 
		result++;
	}
	if(pastures[x][y+1] == 'C'){
		result++;
	}
	return result;
}

int main(){
	
	memset(pastures, '*', sizeof(pastures));
	int n, m;
	cin>>n>>m;

	for(int i = 1; i <= n; i++){
		string line;
		cin>>line;
		for(int j = 1; j <= m; j++){
			pastures[i][j] = line[j-1];
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(pastures[i][j] == 'G'){
				cowTo[i][j] = getAdjacentCows(i, j);
			}
		}
	}

  int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(pastures[i][j] == 'G'){
				if(cowTo[i][j]>=2){
					ans++;
				}
				if(pastures[i+1][j-1]=='G'
				    && cowTo[i][j]==2 
				    && cowTo[i+1][j-1]==2
				    && pastures[i][j-1]=='C'
				    && pastures[i+1][j]=='C'){
					ans--;
				}
				if(pastures[i+1][j+1]=='G' 
				    && cowTo[i][j]==2 
				    && cowTo[i+1][j+1]==2
				    && pastures[i][j+1]=='C'
				    && pastures[i+1][j]=='C'){
					ans--;
				}
			}
		}
	}

	cout<<ans;	
	return 0;
}

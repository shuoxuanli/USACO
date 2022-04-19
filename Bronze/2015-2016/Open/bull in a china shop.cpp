#include<bits/stdc++.h>
using namespace std;
bool check(int piece, int x, int y);

int n;
bool pieces[11][8][8];
vector<int> s[11];

int main() {
  freopen("bcs.in", "r", stdin);
  freopen("bcs.out", "w", stdout);
	
  int k;
  cin >> n >> k;
  char c;
  int left, right, top, bottom;
	
  for (int i = 0; i <= k; i++) {
    left = n - 1;
    right = 0;
    top = n - 1;
    bottom = 0;
    for (int j = 0; j < n; j++) {
      for (int l = 0; l < n; l++) {
        cin >> c;
        pieces[i][j][l] = (c == '#');
              
        if (pieces[i][j][l]) {
	  bottom = max(bottom, j);
	  top = min(top, j);
	  right = max(right, l);
	  left = min(left, l);
	}
      }
    }
    s[i] = {left, right, top, bottom};
  }

  for (int i = 1; i <= k; i++) {
    for (int j = i + 1; j <= k; j++) {
      for (int idx = s[i][3] - n + 1; idx <= s[i][2]; idx++) {
        for (int idy = s[i][1] - n + 1; idy <= s[i][0]; idy++) {
	  for (int jdx = s[j][3] - n + 1; jdx <= s[j][2]; jdx++) {
	    for (int jdy = s[j][1] - n + 1; jdy <= s[j][0]; jdy++) {
	      bool good = true;
	      for (int x = 0; x < n; x++) {
	        for (int y = 0; y < n; y++) {
		  bool ipiece = check(i, x + idx, y + idy);
		  bool jpiece = check(j, x + jdx, y + jdy);
                  if (ipiece && jpiece) {
		    good = false;
		    break;
	          }
		  if (pieces[0][x][y] != (ipiece || jpiece)) {
		    good = false;
		    break;
		  }
		}
	        if (!good) {
		  break;
	        }
	      }
	      if (good) {
	        cout << i << " " << j << endl;
		return 0;
	      }
	    }
	  }
        }
      }
    }
  }
}

bool check(int piece, int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n && pieces[piece][x][y];
}

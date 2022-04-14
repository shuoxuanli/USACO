#include<bits/stdc++.h>
using namespace std;

int hb[101];

int getFarthestBlastIndex(int startIndex, int length, bool toLeft) {
  int sourceBlastIndex = startIndex;
  int direction;
  int blastDistance = 1;

  if(toLeft) {
    direction = -1;
  } else {
    direction = 1;
  }

  while(sourceBlastIndex >= 0 && sourceBlastIndex < length) {
    int nextBlastSource = sourceBlastIndex;
    while(nextBlastSource + direction >= 0 && nextBlastSource + direction < length && abs(hb[sourceBlastIndex] - hb[nextBlastSource+direction]) <= blastDistance) {
      nextBlastSource += direction;
    }
    if(sourceBlastIndex == nextBlastSource) {
      break;
    }

    sourceBlastIndex = nextBlastSource;
    blastDistance++;
  }
  return sourceBlastIndex;
}

int main() {
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  int n;
  cin>>n;

  for(int i = 0; i < n; i++) {
    cin>>hb[i];
  }

  sort(hb, hb+n);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    int left = getFarthestBlastIndex(i, n, true);
    int right = getFarthestBlastIndex(i, n, false);
    int temp = right - left + 1;
    ans = max(temp, ans);
  }

  cout<<ans<<endl;
  return 0;
} 

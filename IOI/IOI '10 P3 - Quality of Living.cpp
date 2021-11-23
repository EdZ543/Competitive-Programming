#include <bits/stdc++.h>
using namespace std;

int r, c, h, w;
int grid[3000][3000];

bool good(int x){
	int thresh[r][c];
	int pref[r][c];

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(grid[i][j] > x) thresh[i][j] = -1;
			else if(grid[i][j] == x) thresh[i][j] = 0;
			else if(grid[i][j] < x) thresh[i][j] = 1;
		}
	}

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			pref[i][j] = thresh[i][j];
			if(i) pref[i][j] += pref[i-1][j];
			if(j) pref[i][j] += pref[i][j-1];
			if(i && j) pref[i][j] -= pref[i-1][j-1];
		}
	}

	for(int i=h-1;i<r;i++){
		for(int j=w-1;j<c;j++){
			int sum = pref[i][j];
			if(i-h >= 0) sum -= pref[i-h][j];
			if(j-w >= 0) sum -= pref[i][j-w];
			if(i-h >= 0 && j-w >= 0) sum += pref[i-h][j-w];	
			if(sum >= 0) return true;
		}
	}

	return false;
}

int main(){
	cin >> r >> c >> h >> w;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++) cin >> grid[i][j];
	}

	int lo = 1, hi = r*c;
	for(hi++;lo<hi;){
		int mid = lo+(hi-lo)/2;
		if(good(mid)) hi = mid;
		else lo = mid+1;
	}

	cout << lo;
}

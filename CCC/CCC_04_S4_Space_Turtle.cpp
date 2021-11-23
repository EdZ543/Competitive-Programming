#include <bits/stdc++.h>
using namespace std;
#define ll long long

double calc_dist(int x, int y, int z){
	return pow(x, 2)+pow(y, 2)+pow(z, 2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int sx, sy, sz, tx, ty, tz; cin >> sx >> sy >> sz >> tx >> ty >> tz;
	tx -= sx;
	ty -= sy;
	tz -= sz;
	double sol = calc_dist(tx, ty, tz);
	while(true){
		int dist; cin >> dist;
		char turn; cin >> turn;

		int x1 = tx;
		tx -= dist;
		if(x1 > 0 && tx < 0){
			sol = min(sol, calc_dist(0, ty, tz));
		}else{
			sol = min(sol, calc_dist(x1, ty, tz));
			sol = min(sol, calc_dist(tx, ty, tz));
		}

		if(turn == 'E'){
			break;
		}else if(turn == 'L'){
			swap(tx, ty);
			ty = -ty;
		}else if(turn == 'R'){
			swap(tx, ty);
			tx = -tx;
		}else if(turn == 'U'){
			swap(tx, tz);
			tz = -tz;	
		}else if(turn == 'D'){
			swap(tx, tz);
			tx = -tx;
		}
	}
	cout << fixed << setprecision(2) << sqrt(sol) << "\n";
}
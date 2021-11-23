#include <bits/stdc++.h>
using namespace std;

const int LEAVES = pow(2, 21);
const int SIZE = pow(2, 22)+5;

int n, k;
int u[SIZE], d[SIZE];

void combine(int p, int c){
	d[c] = min(d[c], d[p]);
	d[c] = max(d[c], u[p]);
	u[c] = max(u[c], u[p]);
	u[c] = min(u[c], d[p]);
}

void update(int x, int t, int l, int r, int h, int a, int b){
	if(a > r || b < l) return;
	if(a >= l && b <= r){
		if(t == 1){
			d[x] = max(d[x], h);
			u[x] = max(u[x], h);
		}else{
			d[x] = min(d[x], h);
			u[x] = min(u[x], h);
		}
		return;
	}

	combine(x, 2*x);
	combine(x, 2*x+1);
	d[x] = SIZE, u[x] = 0;

	int m = (a+b)/2;
	update(x*2, t, l, r, h, a, m);
	update(x*2+1, t, l, r, h, m+1, b);
}

int main(){
	cin >> n >> k;

	for(int i=0;i<k;i++){
		int t, l, r, h; cin >> t >> l >> r >> h;
		update(1, t, l+1, r+1, h, 1, LEAVES);
	}

	for(int i=1;i<LEAVES;i++){
		combine(i, 2*i);
		combine(i, 2*i+1);
	}

	for(int i=LEAVES;i<LEAVES+n;i++) cout << min(d[i], u[i]) << '\n';
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
	::n = n;
	::k = k;

	for(int i=0;i<k;i++){
		int t = op[i], l = left[i], r = right[i], h = height[i];
		update(1, t, l+1, r+1, h, 1, LEAVES);
	}

	for(int i=1;i<LEAVES;i++){
		combine(i, 2*i);
		combine(i, 2*i+1);
	}

	for(int i=LEAVES;i<LEAVES+n;i++) finalHeight[i-LEAVES] = min(d[i], u[i]);

}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

int n;
int h[MAXN], a[MAXN];

struct segtree{
	int size = 1;
	vector<long long> vals;

	void init(int n){
		while(size < n) size *= 2;
		vals.assign(2*size, 0);
	}

	void set(int i, long long v, int x = 0, int lx = 0, int rx = -1){
		if(rx == -1) rx = size;
		if(rx-lx == 1){
			vals[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		if(i < m) set(i, v, 2*x+1, lx, m);
		else set(i, v, 2*x+2, m, rx);
		vals[x] = max(vals[2*x+1], vals[2*x+2]);
	}

	long long get_max(int l, int r, int x = 0, int lx = 0, int rx = -1){
		if(rx == -1) rx = size;
		if(lx >= r || rx <= l) return 0;
		if(lx >= l && rx <= r) return vals[x];
		int m = (lx+rx)/2;
		long long m1 = get_max(l, r, 2*x+1, lx, m);
		long long m2 = get_max(l, r, 2*x+2, m, rx);
		return max(m1, m2);
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	for(int i=0;i<n;i++) cin>>h[i];
	for(int i=0;i<n;i++) cin>>a[i];

	segtree st;
	st.init(n);

	vector<long long> dp(n+1, 0);
	long long sol = 0;
	for(int i=0;i<n;i++){
		long long m = st.get_max(0, h[i]-1)+a[i];
		st.set(h[i]-1, m);
		sol = max(sol, m);
	}

	cout<<sol;
}

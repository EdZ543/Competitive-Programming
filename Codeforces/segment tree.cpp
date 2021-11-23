#include <bits/stdc++.h>
using namespace std;

struct segtree{
	int size;
	vector<long long> operations;
	vector<long long> values;

	long long NO_OPERATION = LLONG_MAX;
	long long NEUTRAL_ELEMENT = 0;

	long long modify_op(long long a, long long b, long long len){
		if(b == NO_OPERATION) return a;
		return b*len;
	}

	long long calc_op(long long a, long long b){
		return a+b;
	}

	void apply_mod_op(long long &a, long long b, long long len){
		a = modify_op(a, b, len);
	}

	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		operations.assign(2*size, 0);
		values.assign(2*size, 0);
	}

	void propagate(int x, int lx, int rx){
		if(rx-lx == 1) return;
		int m = (lx+rx)/2;
		apply_mod_op(operations[2*x+1], operations[x], 1);
		apply_mod_op(values[2*x+1], operations[x], m-lx);
		apply_mod_op(operations[2*x+2], operations[x], 1);
		apply_mod_op(values[2*x+2], operations[x], rx-m);
		operations[x] = NO_OPERATION;
	}

	void modify(int l, int r, int v, int x, int lx, int rx){
		propagate(x, lx, rx);
		if(lx >= r || l >= rx) return;
		if(lx >= l && rx <= r){
			apply_mod_op(operations[x], v, 1);
			apply_mod_op(values[x], v, rx-lx);
			return;
		}
		int m = (lx+rx)/2;
		modify(l, r, v, 2*x+1, lx, m);
		modify(l, r, v, 2*x+2, m, rx);
		values[x] = calc_op(values[2*x+1], values[2*x+2]);
		apply_mod_op(values[x], operations[x], rx-lx);
	}

 	void modify(int l, int r, int v){
		modify(l, r, v, 0, 0, size);
	}

	long long calc(int l, int r, int x, int lx, int rx){
		propagate(x, lx, rx);
		if(lx >= r || l >= rx) return NEUTRAL_ELEMENT;
		if(lx >= l && rx <= r) return values[x];
		int m = (lx+rx)/2;
		auto m1 = calc(l, r, 2*x+1, lx, m);
		auto m2 = calc(l, r, 2*x+2, m, rx);
		auto res = calc_op(m1, m2);
		apply_mod_op(res, operations[x], min(rx, r)-max(lx, l));
		return res;
	}

	long long calc(int l, int r){
		return calc(l, r, 0, 0, size);
	}

	long long get(int i, int x, int lx, int rx){
		if(rx-lx == 1) return operations[x];
		int m = (lx+rx)/2;
		if(i < m) return operations[x]+get(i, 2*x+1, lx, m);
		else return operations[x]+get(i, 2*x+2, m, rx);
	}

	long long get(int i){
		return get(i, 0, 0, size);
	}

	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx == 1){
			operations[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		if(i < m) set(i, v, 2*x+1, lx, m);
		else set(i, v, 2*x+2, m, rx);
		operations[x] = operations[2*x+1]+operations[2*x+2];
	}

	void set(int i, int v){
		set(i, v, 0, 0, size);
	}

	long long sum(int l, int r, int x, int lx, int rx){
		if(lx >= r || l >= rx) return 0;
		if(lx >= l && rx <= r) return operations[x];
		int m = (lx+rx)/2;
		long long s1 = sum(l, r, 2*x+1, lx, m);
		long long s2 = sum(l, r, 2*x+2, m, rx);
		return s1+s2;
	}

	long long sum(int l, int r){
		return sum(l, r, 0, 0, size);
	}
};

int main(){
	int n, m;
	cin >> n >> m;

	segtree st;
	st.init(n);

	while(m--){
		int op; cin >> op;
		if(op == 1){
			int l, r, v; cin >> l >> r >> v;
			st.modify(l, r, v);
		}else{
			int l, r; cin >> l >> r;
			cout << st.calc(l, r) << "\n";
		}
	}
}

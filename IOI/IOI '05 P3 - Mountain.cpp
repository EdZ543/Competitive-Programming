#include <bits/stdc++.h>
using namespace std;

const int MAXN = 153456;
const int NO_LAZY = INT_MAX;

struct seg{
	int sum, max, lazy, tl, tr, l, r;
	seg():sum(0), max(0), lazy(NO_LAZY), l(-1), r(-1){};
};

seg segs[64*MAXN];
int cnt = 0;

void update_op(seg &a, int lazy){
	if(lazy == NO_LAZY) return;
	a.sum = (a.tr-a.tl)*lazy;
	a.max = (a.tr-a.tl)*lazy;
	a.lazy = lazy;
}

seg query_op(seg x, seg a, seg b){
	x.sum = a.sum+b.sum;
	x.max = max(a.max, a.sum+b.max);
	return x;
}

void create(int x){
	if(segs[x].tr-segs[x].tl == 1) return;
	int m = (segs[x].tl+segs[x].tr)/2;
	if(segs[x].l == -1){
		segs[x].l = ++cnt;
		segs[segs[x].l].tl = segs[x].tl;
		segs[segs[x].l].tr = m;
	}
	if(segs[x].r == -1){
		segs[x].r = ++cnt;
		segs[segs[x].r].tl = m;
		segs[segs[x].r].tr = segs[x].tr;
	}
}

void propagate(int x) {
	if(segs[x].tr-segs[x].tl == 1) return;
	create(x);
	update_op(segs[segs[x].l], segs[x].lazy);
	update_op(segs[segs[x].r], segs[x].lazy);
	segs[x].lazy = NO_LAZY;
}

void update(int x, int l, int r, int v) {
	propagate(x);
	if(segs[x].tl >= r || segs[x].tr <= l) return;
	if(segs[x].tl >= l && segs[x].tr <= r){
		update_op(segs[x], v);
		return;
	}
	update(segs[x].l, l, r, v);
	update(segs[x].r, l, r, v);
	segs[x] = query_op(segs[x], segs[segs[x].l], segs[segs[x].r]);
}

seg query(int x, int l, int r){
	propagate(x);
	if(segs[x].tl >= r || segs[x].tr <= l) return seg();
	if(segs[x].tl >= l && segs[x].tr <= r) return segs[x];
	seg q1 = query(segs[x].l, l, r);
	seg q2 = query(segs[x].r, l, r);
	return query_op(segs[x], q1, q2);
}

int ask(int x, int h, int psum){
	propagate(x);
	if(psum+segs[x].max <= h) return segs[x].tr-segs[x].tl;
	if(segs[x].tr-segs[x].tl == 1) return 0;
	int ret = ask(segs[x].l, h, psum);
	if(ret == segs[segs[x].l].tr-segs[segs[x].l].tl) ret += ask(segs[x].r, h, psum+segs[segs[x].l].sum);
	return ret;
}

int main() {
	int n; cin >> n;

	segs[0].tl = 0;
	segs[0].tr = n;

	while(1){
		char op; cin >> op;
		if(op == 'I'){
			int l, r, v; cin >> l >> r >> v;
			update(0, l-1, r, v);
		}else if(op == 'Q'){
			int h; cin >> h;
			cout << ask(0, h, 0) << "\n";
		}else if(op == 'E') break;
	}
}

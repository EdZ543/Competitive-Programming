#include <bits/stdc++.h>
using namespace std;

struct Segtree{
    long long rsize, csize;
    vector<vector<long long>> sums;

    void init(long long r, long long c){
        rsize = 1;
        while(rsize < r) rsize *= 2;
		csize = 1;
		while(csize < c) csize *= 2;
        sums.assign(2*rsize, vector<long long>(2*csize, 0));
    }

    void set(long long x, long long y, long long a, long long indx, long long indy, long long lx, long long rx, long long by, long long ty){
        if(rx-lx == 1 && ty-by == 1){
            sums[indy][indx] = a;
            return;
        }

        long long mx = lx+(rx-lx)/2;
        long long my = by+(ty-by)/2;

        if(x < mx && y < my){
            set(x, y, a, 2*indx+1, 2*indy+1, lx, mx, by, my);
        }else if(x >= mx && y < my){
            set(x, y, a, 2*indx+2, 2*indy+1, mx, rx, by, my);
        }else if(x < mx && y >= my){
            set(x, y, a, 2*indx+1, 2*indy+2, lx, mx, my, ty);
        }else if(x >= mx && y >= my){
            set(x, y, a, 2*indx+2, 2*indy+2, mx, rx, my, ty);
        }
       
        sums[indy][indx] = gcd(gcd(gcd(sums[2*indy+1][2*indx+1], sums[2*indy+2][2*indx+1]), sums[2*indy+1][2*indx+2]), sums[2*indy+2][2*indx+2]);
    }

    void set(long long x, long long y, long long a){
        set(x, y, a, 0, 0, 0, csize, 0, rsize);
    }

    long long sum(long long l, long long r, long long b, long long t, long long indx, long long indy, long long lx, long long rx, long long by, long long ty){
        if(lx >= r || rx <= l || by >= t || ty <= b) return 0;
        if (lx >= l && rx <= r && by >= b && ty <= t) return sums[indy][indx];

        long long mx = lx+(rx-lx)/2;
        long long my = by+(ty-by)/2;

        long long s1 = sum(l, r, b, t, 2*indx+1, 2*indy+1, lx, mx, by, my);
        long long s2 = sum(l, r, b, t, 2*indx+2, 2*indy+1, mx, rx, by, my);
        long long s3 = sum(l, r, b, t, 2*indx+1, 2*indy+2, lx, mx, my, ty);
        long long s4 = sum(l, r, b, t, 2*indx+2, 2*indy+2, mx, rx, my, ty);

        return gcd(gcd(gcd(s1, s2), s3), s4);
    }

    long long sum(long long l, long long r, long long b, long long t){
        return sum(l, r, b, t, 0, 0, 0, csize, 0, rsize);
    }
};

long long R, C, N;

int main(){
	cin >> R >> C >> N;

	Segtree segtree;
	segtree.init(max(R, C), max(R, C));

	for(long long i=0;i<N;i++){
		long long type; cin >> type;
		if(type == 1){
			long long x, y, a; cin >> y >> x >> a;
			segtree.set(x, y, a);
		}else{
			long long l, r, b, t; cin >> b >> l >> t >> r;
			cout << segtree.sum(l, r+1, b, t+1) << '\n';
		}
	}
}

#include <bits/stdc++.h>
using namespace std;

long long r, l, b, rfs[100000], psum[100000];

long long cost(long long x, long long y){
	long long p = (x+y)/2;
	return (p-x)*rfs[p]-(psum[p]-psum[x])+(psum[y+1]-psum[p+1])-(y-p)*rfs[p];
}

bool good(long long x){
	for(long long i=0;i<r-x+1;i++) if(cost(i, i+x-1) <= b) return true;
	return false;
}

int main(){
	cin >> r >> l >> b;
	for(long long i=0;i<r;i++) cin >> rfs[i];

	long long sum = 0;
	for(int i=0;i<=r;i++){
		psum[i] = sum;
		sum += rfs[i];
	}

	long long lo = 0, hi = r;
	for(--lo;lo<hi;){
		long long mid = lo+(hi-lo+1)/2;
		if(good(mid)) lo = mid;
		else hi = mid-1;
	}

	cout << lo;
}

int besthub(int R, int L, int X[], long long B){
	r = R;
	l = L;
	b = B;
	for(int i=0;i<r;i++) rfs[i] = X[i];

	long long sum = 0;
	for(int i=0;i<=r;i++){
		psum[i] = sum;
		sum += rfs[i];
	}

	long long lo = 0, hi = r;
	for(--lo;lo<hi;){
		long long mid = lo+(hi-lo+1)/2;
		if(good(mid)) lo = mid;
		else hi = mid-1;
	}

	return lo;
}

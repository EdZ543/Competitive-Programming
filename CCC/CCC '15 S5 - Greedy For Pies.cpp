#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> a, b;
long long dp[3001][101][101][2];

long long rec(long long v, long long bl, long long br, bool tp){
	if(dp[v][bl][m-1-br][tp] != -1) return dp[v][bl][m-1-br][tp];

	long long ret = 0;
	if(!tp && v < n){
		ret = max(ret, a[v]+rec(v+1, bl, br, true));	
		if(bl <= br) ret = max(ret, b[br]+rec(v, bl, br-1, true));
		ret = max(ret, rec(v+1, bl, br, false));
	}else if(tp && v < n){
		ret = max(ret, rec(v+1, bl, br, false));
		if(bl <= br) ret = max(ret, rec(v, bl+1, br, false));
	}else if(v == n){
		if(!tp && bl <= br) ret = max(ret, b[br]+rec(v, bl, br-1, true));
		if(tp && bl <= br) ret = max(ret, rec(v, bl+1, br, false));
	}

	dp[v][bl][m-1-br][tp] = ret;
	return ret;
}

int main(){
	cin >> n;
	for(long long i=0;i<n;i++){
		long long x; cin >> x;
		a.push_back(x);
	}
	cin >> m;
	for(long long i=0;i<m;i++){
		long long x; cin >> x;
		b.push_back(x);
	}
	sort(b.begin(), b.end());
	memset(dp, -1, sizeof(dp));

	cout << rec(0, 0, m-1, false);
}

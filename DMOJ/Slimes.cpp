#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400;

int n;
vector<int> sz;
vector<long long> pref;
long long dp[MAXN][MAXN];

long long rec(int l = 0, int r = n-1){
	if(dp[l][r] != -1) return dp[l][r];
	if(l == r) return 0;
	long long ret = LLONG_MAX;
	for(int i=l;i<r;i++){
		long long lsum = rec(l, i);
		long long rsum = rec(i+1, r);
		long long allsum = pref[r];
		if(l != 0) allsum -= pref[l-1];
		ret = min(ret, lsum+rsum+allsum);
	}
	return dp[l][r] = ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	long long cursum = 0;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		sz.push_back(x);
		cursum += x;
		pref.push_back(cursum);
	}

	memset(dp, -1, sizeof dp);
	cout<<rec();
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000;

int n;
vector<int> a;
long long dp[MAXN][MAXN][2][2];

long long rec(int l, int r, int t, int p){
	if(l > r) return 0;
	if(dp[l][r][t][p] != -1) return dp[l][r][t][p];
	long long ret;
	if(t == p){
		ret = max(a[l]+rec(l+1, r, 1-t, p), a[r]+rec(l, r-1, 1-t, p));
	}else{
		ret = min(rec(l+1, r, 1-t, p), rec(l, r-1, 1-t, p));
	}
	return dp[l][r][t][p] = ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		a.push_back(x);
	}

	memset(dp, -1, sizeof dp);

	cout<<rec(0, n-1, 0, 0)-rec(0, n-1, 0, 1);
}

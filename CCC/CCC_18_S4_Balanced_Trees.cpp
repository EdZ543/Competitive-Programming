#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> dp;

long long subtrees(long long n){
	if(n == 1) return 1;
	if(dp.find(n) != dp.end()) return dp[n];
	long long ret = 0;
	for(long long k=2;k<=n;k++){
		long long r = n%k;
		long long d = n/k;
		long long extra = r/d;
		long long count = extra+1;
		ret += count*subtrees(d);
		k += count-1;
	}
	dp.insert({n, ret});
	return ret;
}

int main(){
	long long n; cin >> n;
	cout << subtrees(n);
}
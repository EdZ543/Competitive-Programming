#include <bits/stdc++.h>
using namespace std;

long long n;
pair<long long, long long> pis[100000];
long long dp[100000][2];

int main(){
	cin >> n;
	for(long long i=0;i<n;i++) cin >> pis[i].first >> pis[i].second;

	for(long long i=0;i<n;i++){
		long long a = dp[i-1][0]+max(0LL, pis[i].first-pis[i-1].second);
		long long b = dp[i-1][1]+pis[i].first;
		dp[i][0] = min(a, b);

		long long c = dp[i-1][0]+max(0LL, pis[i].first-pis[i-1].second-pis[i+1].second);
		long long d = dp[i-1][1]+max(0LL, pis[i].first-pis[i+1].second);
		dp[i][1] = min(c, d);
	}

	cout << dp[n-1][0];
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n, k;
int h[MAXN];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>h[i];

	long long dp[n];
	dp[0] = 0;
	for(int i=1;i<n;i++){
		dp[i] = dp[i-1]+abs(h[i]-h[i-1]);
		for(int j=max(0, i-k);j<i;j++) dp[i] = min(dp[i], dp[j]+abs(h[i]-h[j]));
	}

	cout<<dp[n-1];
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n;
int h[MAXN];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	for(int i=0;i<n;i++) cin>>h[i];

	long long dp[n];
	dp[0] = 0;
	dp[1] = abs(h[1]-h[0]);
	for(int i=2;i<n;i++) dp[i] = min(dp[i-2]+abs(h[i]-h[i-2]), dp[i-1]+abs(h[i]-h[i-1]));

	cout<<dp[n-1];
}

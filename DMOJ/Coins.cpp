#include <bits/stdc++.h>
using namespace std;

int n;
vector<double> ps;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		double p; cin>>p;
		ps.push_back(p);
	}

	vector<vector<double>> dp(n, vector<double>(n+1));
	dp[0][0] = ((double)1-ps[0]);
	dp[0][1] = ps[0];
	for(int i=2;i<=n;i++) dp[0][i] = 0;
	for(int i=1;i<n;i++){
		dp[i][0] = dp[i-1][0]*((double)1-ps[i]);
		for(int j=1;j<=n;j++){
			double hp = ps[i]*dp[i-1][j-1];
			double tp = ((double)1-ps[i])*dp[i-1][j];
			dp[i][j] = hp+tp;
		}
	}

	double sol = 0;
	for(int i=ceil((double)n/2);i<=n;i++) sol += dp[n-1][i];
	cout<<setprecision(100)<<sol;
}

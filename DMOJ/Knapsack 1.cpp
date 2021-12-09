#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, w; cin>>n>>w;

	vector<long long> dp(w+1);
	for(int i=0;i<n;i++){
		long long we, va; cin>>we>>va;
		for(int j=w-we;j>=0;j--) dp[j+we] = max(dp[j+we], dp[j]+va);	
	}

	long long sol = 0;
	for(int i=0;i<=w;i++) sol = max(sol, dp[i]);
	cout<<sol;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin>>n>>k;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		a.push_back(x);
	}

	vector<vector<int>> dp(k+1, vector<int>(2));
	for(int i=0;i<=k;i++){
		dp[i][0] = 1;
		for(int j=0;j<n;j++){
			if(a[j] > i) continue;
			if(dp[i-a[j]][1] == 0){
				dp[i][0] = 0;
			}
		}	

		dp[i][1] = 0;
		for(int j=0;j<n;j++){
			if(a[j] > i) continue;
			if(dp[i-a[j]][0] == 1){
				dp[i][1] = 1;
			}
		}	
	}

	cout<<(dp[k][0]?"Second":"First");
}

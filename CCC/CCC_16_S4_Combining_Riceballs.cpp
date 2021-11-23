#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int dp[402][402] = {0};
int sum[402];
int ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> dp[i][i];
		ans = max(ans, dp[i][i]);
		if(!i){
			sum[0] = dp[i][i];
		}else{
			sum[i] = sum[i-1]+dp[i][i];
		}
	}
	for(int len=1;len<n;len++){
		for(int l=0;l<n-len;l++){
			int r = l+len;
			int j = l+1;
			int k = r;
			while(j <= k){
				if(dp[l][j-1] && dp[l][j-1] == dp[k][r] && (j == k || dp[j][k-1])){
					dp[l][r] = max(dp[l][r], dp[l][j-1]+dp[j][k-1]+dp[k][r]);
					ans = max(ans, dp[l][r]);
					break;
				}
				if(sum[j-1]-sum[l-1] < sum[r]-sum[k-1]){
					j++;
				}else{
					k--;
				}
			}
		}
	}
	cout << ans << "\n";
}
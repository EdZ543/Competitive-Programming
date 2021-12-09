#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

void add_self(int& a, int b){
	a += b;
	if(a >= mod) a -= mod;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long k; 
	cin>>n>>k;

	vector<vector<int>> can(n, vector<int>(n));

	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>can[i][j];

	vector<int> dp(n, 1);

	for(long long step=0;step<k;step++){
		vector<int> dp2(n);
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				if(can[a][b]){
					add_self(dp2[b], dp[a]);
				}
			}
		}
		dp = dp2;
	}

	int sol = 0;
	for(int i=0;i<n;i++){
		sol += dp[i];
	}
	cout<<sol;
}

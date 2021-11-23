#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1, MAXA = 101;

int n;
int val[MAXN];
long long dp[2][4][MAXA] = {0};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++) cin>>val[i];

	dp[0][0][0] = 1;

	long long sol = 0;
	int ind = 1, pind = 0;
	for(int i=1;i<=n;i++){
		for(int y=0;y<=3;y++){
			for(int z=0;z<=100;z++){
				dp[ind][y][z] = dp[pind][y][z];
				if(y >= 1 && z >= val[i]) dp[ind][y][z] += dp[pind][y-1][z-val[i]];
			}
		}
		sol += dp[pind][3][val[i]];
		ind = 1-ind;
		pind = 1-pind;
	}

	cout<<sol;
}

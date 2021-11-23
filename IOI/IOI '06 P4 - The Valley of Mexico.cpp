#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

int c, n;
bool adj[MAXN][MAXN];
int dp[MAXN][MAXN];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>c>>n;
	for(int i=0;i<n;i++){
		int a, b; cin>>a>>b;
		adj[a][b] = true;
		adj[b][a] = true;
	}

	memset(dp, -1, sizeof dp);

	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(
		}
	}
}

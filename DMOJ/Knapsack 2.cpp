#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, W; cin>>N>>W;

	const int MAXV = 100*1e3;
	vector<long long> dp(MAXV+1, 100*1e9);
	dp[0] = 0;
	for(int i=0;i<N;i++){
		int w, v; cin>>w>>v;
		for(int j=MAXV-v;j>=0;j--) dp[j+v] = min(dp[j+v], dp[j]+w);
	}

	for(int i=MAXV;i>=0;i--) if(dp[i] <= W){
		cout<<i;
		break;
	}
}

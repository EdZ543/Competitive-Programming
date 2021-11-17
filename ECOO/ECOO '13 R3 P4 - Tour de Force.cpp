#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1000, -1);
vector<pair<int, int>> cards(1000);
int n;

int dfs(int v){
	if(dp[v] != -1) return dp[v];
	if(v >= n-5) return cards[v].second+1;
	int ret = INT_MAX;
	for(int i=1;i<=5;i++){
		ret = min(ret, dfs(v+i));	
	}
	ret += cards[v].second+1;
	dp[v] = ret;
	return ret;
}

int main(){
	vector<int> sols;
	for(int i=0;i<10;i++){
		cin >> n;
		int sum = 0;
		dp.assign(1000, -1);
		cards.assign(1000, {});
		for(int j=0;j<n;j++){
			cin >> cards[j].first >> cards[j].second;
			sum += cards[j].first + cards[j].second;
		}

		int minLoss = INT_MAX;
		for(int j=0;j<5;j++){
			minLoss = min(minLoss, dfs(j));
		}

		sols.push_back(sum-minLoss);
	}
	for(auto sol:sols) cout << sol << '\n';
}

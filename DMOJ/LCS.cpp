#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s, t; cin>>s>>t;
	using T = pair<int, pair<int, int>>;
	vector<vector<T>> dp(s.size()+1, vector<T>(t.size()+1, {0, {-1, -1}}));

	for(int i=0;i<s.size();i++){
		for(int j=0;j<t.size();j++){
			if(s[i] == t[j]){
				if(dp[i+1][j+1].first <= dp[i][j].first+1){
					dp[i+1][j+1].first = dp[i][j].first+1;
					dp[i+1][j+1].second = {i, j};
				}
				continue;
			}
			if(dp[i+1][j].first <= dp[i][j].first){
				dp[i+1][j].first = dp[i][j].first;
				dp[i+1][j].second = {i, j};
			}
			if(dp[i][j+1].first <= dp[i][j].first){
				dp[i][j+1].first = dp[i][j].first;
				dp[i][j+1].second = {i, j};
			}
		}
	}

	int maxl = 0;
	pair<int, int> maxp;
	for(int i=0;i<=s.size();i++){
		for(int j=0;j<=t.size();j++){
			if(dp[i][j].first > maxl){
				maxl = dp[i][j].first;
				maxp = dp[i][j].second;
			}
		}
	}

	string sol = "";
	while(maxp.first != -1){
		if(s[maxp.first] == t[maxp.second]){
			sol = s[maxp.first]+sol;
		}
		maxp = dp[maxp.first][maxp.second].second;
	}

	cout<<sol;
}

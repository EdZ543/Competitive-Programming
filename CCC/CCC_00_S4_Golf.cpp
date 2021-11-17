#include <bits/stdc++.h>
using namespace std;
#define ll long long

int d, n;
vector<int> dp(5281, -1);
vector<int> clubs(32);

int strokes(int v, vector<bool> visited){
	if(dp[v] != -1) return dp[v];
	visited[v] = true;
	int ret = INT_MAX;
	for(int i=0;i<n;i++){
		int next = v-clubs[i];
		if(next >= 0 && !visited[next]){
			int nextStrokes = strokes(next, visited);
			if(nextStrokes != INT_MAX) ret = min(ret, nextStrokes+1);
		}
	}
	dp[v] = ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> d >> n;
	for(int i=0;i<n;i++) cin >> clubs[i];
	dp[0] = 0;
	vector<bool> visited(5281);
	int sol = strokes(d, visited);
	sol == INT_MAX ? cout << "Roberta acknowledges defeat.\n" : cout << "Roberta wins in " << sol << " strokes.\n";
}
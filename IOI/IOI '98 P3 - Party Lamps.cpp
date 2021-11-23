#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> ons;
vector<int> offs;
set<vector<bool>> sols;
map<pair<int, vector<bool>>, bool> visited;

vector<bool> change(vector<bool> sol, int bu){
	int st, inc;

	if(bu == 1) st = 1, inc = 1;
	else if(bu == 2) st = 1, inc = 2;
	else if(bu == 3) st = 2, inc = 2;
	else if(bu == 4) st = 1, inc = 3;

	for(int i=st;i<=n;i+=inc){
		if(sol[i]) sol[i] = 0;
		else sol[i] = 1;
	}	

	return sol;
}

bool good(vector<bool> sol){
	for(auto on:ons) if(!sol[on]) return false;
	for(auto off:offs) if(sol[off]) return false;
	return true;
}

void dfs(int v, vector<bool> sol){
	if(v == c){
		if(good(sol)) sols.insert(sol);
		return;
	}
	if(visited[{v, sol}]) return;
	visited[{v, sol}] = true;

	dfs(v+1, change(sol, 1));
	dfs(v+1, change(sol, 2));
	dfs(v+1, change(sol, 3));
	dfs(v+1, change(sol, 4));
}

int main(){
	cin >> n >> c;
	while(true){
		int on; cin >> on;
		if(on == -1) break;
		ons.push_back(on);
	}
	while(true){
		int off; cin >> off;
		if(off == -1) break;
		offs.push_back(off);
	}

	dfs(0, vector<bool>(n+1, 1));
	if(sols.empty()) cout << "IMPOSSIBLE";
	else{
		for(auto sol:sols){
			for(int i=1;i<=n;i++) cout << sol[i];
			cout << '\n';
		}
	}
}

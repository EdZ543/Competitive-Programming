#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;
int n, m;
vector<int> adj[MAXN];
vector<int> sol;
vector<bool> visited(MAXN, false);

void dfs(int v){
	visited[v] = true;
	for(auto u:adj[v]){
		if(visited[u]) continue;
		dfs(u);
	}
	sol.push_back(v);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}

	for(int i=1;i<=n;i++) if(!visited[i]) dfs(i);
	reverse(sol.begin(), sol.end());

	vector<int> ind(MAXN);
	for(int i=1;i<=n;i++) ind[sol[i]] = i;
	for(int i=1;i<=n;i++) for(auto j:adj[i]) if(ind[j] <= ind[i]){
		cout << "IMPOSSIBLE";
		return 0;
	}
	for(auto i:sol) cout << i << " ";
}

#include <bits/stdc++.h>
using namespace std;

int n, dist = 1;
char r;
vector<int> adj[10001];

void bfs(int v){
	vector<bool> visited(10001);
	vector<int> parent(10001);
	queue<int> q;
	q.push(v);
	visited[v] = true;
	int dest = 0;
	int pages = 1;

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		if(adj[cur].empty() && dest == 0){
			dest = cur;
		}
		for(auto u:adj[cur]){
			if(!visited[u]){
				visited[u] = true;
				q.push(u);
				parent[u] = cur;
				pages++;
			}
		}
	}

	while(dest != 1){
		dest = parent[dest];
		dist++;
	}

	r = pages == n ? 'Y' : 'N';
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		int m; cin >> m;
		for(int j=0;j<m;j++){
			int a; cin >> a;
			adj[i].push_back(a);
		}
	}
	bfs(1);
	cout << r << "\n";
	cout << dist << "\n";
}
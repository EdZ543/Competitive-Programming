#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;

int n;
int adj[MAXN], dist[MAXN], ans[MAXN];
bool in_cycle;

void rec(int x, int d = 0){
	if(ans[x] != -2){
		if(ans[x] == -1) ans[x] = d-dist[x], in_cycle = 1;
		return;
	}
	dist[x] = d;
	ans[x] = -1; rec(adj[x], d+1);
	if(ans[x] != -1){in_cycle = 0; return;}
	ans[x] = in_cycle?ans[adj[x]]:ans[adj[x]]+1;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>adj[i];
	for(int i=1;i<=n;i++) ans[i] = -2;
	for(int i=1;i<=n;i++) rec(i);
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}

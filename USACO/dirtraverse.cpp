#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 1e5+1;

long long n;
vector<long long> adj[MAXN];
long long len[MAXN] = {0}, num[MAXN] = {0}, ulen[MAXN];
bool file[MAXN] = {0};
long long name[MAXN];

void setIO(string s){
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

void dfs1(long long cur = 1, long long par = -1){
	for(auto u:adj[cur]) if(u != par){
		if(file[u]){
			num[cur]++;
			len[cur] += name[u];
		}else{
			dfs1(u, cur);
			num[cur] += num[u];
			len[cur] += num[u]*(name[u]+1)+len[u];
		}
	}
}

void dfs2(long long cur = 1, long long par = -1){
	if(cur == 1) ulen[cur] = 0;
	else ulen[cur] = (ulen[par]+3*(num[1]-num[par]))+(len[par]-len[cur]-num[cur]*(name[cur]+1)+3*(num[par]-num[cur]));
	for(auto u:adj[cur]) if(u != par && !file[u]) dfs2(u, cur);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	setIO("dirtraverse");

	cin>>n;
	for(long long i=1;i<=n;i++){
		string na; cin>>na;
		long long m; cin>>m;
		if(!m) file[i] = true;
		name[i] = na.size();
		for(long long j=0;j<m;j++){
			long long b; cin>>b;
			adj[i].push_back(b);
			adj[b].push_back(i);
		}
	}

	dfs1();
	dfs2();

	long long sol = LLONG_MAX;
	for(long long i=1;i<=n;i++) if(!file[i]) sol = min(sol, len[i]+ulen[i]);
	cout<<sol;
}

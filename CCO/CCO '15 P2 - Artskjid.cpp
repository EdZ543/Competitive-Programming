#include <bits/stdc++.h>
using namespace std;

#define MAXN 18
#define NINF LLONG_MIN
using ll = long long;

ll n, m;
vector<pair<ll, ll>> adj[MAXN];
ll dp[1<<MAXN][MAXN];

ll dfs(ll bits, ll v){
	if(dp[bits][v] != -1) return dp[bits][v];

	ll ret = 0;
	bool send = true;
	for(auto u:adj[v]){
		if(bits&(1<<u.first)){
			ll next = dfs(bits^(1<<u.first), u.first);
			if(next != NINF){
				send = false;
				ret = max(ret, u.second+next);
			}
		}
	}
	
	if(send && bits&(1<<(n-1))) return dp[bits][v] = NINF;
	return dp[bits][v] = ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	memset(dp, -1, sizeof dp);
	for(ll i=0;i<m;i++){
		ll a, b, c; cin>>a>>b>>c;
		adj[a].push_back({b, c});
	}
	for(ll i=0;i<(1<<n);i++) dp[i][n-1] = 0;

	ll start = (1<<n)-1;
    start = start&~(1);
	cout<<dfs(start, 0);
}

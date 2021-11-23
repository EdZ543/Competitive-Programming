#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int n;
int adj[MAXN], ans[MAXN];
bool in_cycle = false;

void setIO(string s){
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

void rec(int cur){
	if(ans[cur] != -2){
		if(ans[cur] == -1){
			ans[cur] = cur;
			in_cycle = true;
		}
		return;
	}
	ans[cur] = -1;
	rec(adj[cur]);
	if(ans[cur] != -1){
		in_cycle = false;
		return;
	}
	ans[cur] = in_cycle?cur:ans[adj[cur]];
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	setIO("shuffle");

	cin>>n;
	for(int i=1;i<=n;i++) cin>>adj[i];
	for(int i=0;i<=n;i++) ans[i] = -2;
	for(int i=1;i<=n;i++) rec(i);
	int sol = 0;
	for(int i=1;i<=n;i++) sol += ans[i] == i;
	cout<<sol;
}

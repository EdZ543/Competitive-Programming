#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

int n;
int adj[MAXN], ans[MAXN];
bool in_cycle = false;

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

	cin>>n;
	for(int i=1;i<=n;i++) cin>>adj[i];
	for(int i=0;i<=n;i++) ans[i] = -2;
	for(int i=1;i<=n;i++) rec(i);
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}

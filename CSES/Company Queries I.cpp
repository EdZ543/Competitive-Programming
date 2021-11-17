#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+1;
const int MJ = 18; // 18 is calculated by $\log_2 2e5$

int n, q;
int up[MN][MJ];

int jmp(int a, int b){
	for(int i=0;i<MJ;i++) if((b>>i)&1) a = up[a][i];
	return a?:-1;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int a; cin>>a;
		up[i][0] = a;
	}

	for(int i=1;i<=n;i++) for(int j=1;j<MJ;j++) up[i][j] = up[up[i][j-1]][j-1];

	while(q--){
		int a, b; cin>>a>>b;
		cout<<jmp(a, b)<<"\n";
	}
}

#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+1;
const int MJ = 30;

int n, q;
int up[MN][MJ];

int jmp(int a, int b){
	for(int i=0;i<MJ;i++) if((b>>i)&1) a = up[a][i];
	return a;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>up[i][0];
	for(int j=1;j<MJ;j++) for(int i=1;i<=n;i++) up[i][j] = up[up[i][j-1]][j-1];
	while(q--){
		int a, b; cin>>a>>b;
		cout<<jmp(a, b)<<"\n";
	}
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25e4+1;

int n, m;
int num[MAXN];

int sum(int a, int b){
	int ret = 0;
	for(int i=a;i<=b;i++){
		ret += num[i];
		num[i] = (num[i]+1)%10;
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	string s; cin>>s;
	for(int i=1;i<=n;i++) num[i] = s[i-1]-'0';	
	while(m--){
		int a, b; cin>>a>>b;
		cout<<sum(a, b)<<"\n";
	}
}

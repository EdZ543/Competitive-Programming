#include <bits/stdc++.h>
using namespace std;

int t;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>t;
	while(t--){
		int a, b, c; cin>>a>>b>>c;
		if(b % 2 == 0 || (a >= 1 && c >= 1) || (a >= 2)){
			if(c <= a && (a-c) % 2 == 0){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}	
		}else{
			cout<<"NO\n";
		}
	}	
}

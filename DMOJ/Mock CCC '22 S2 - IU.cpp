#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>s;
	long long sol = 0;
	int target = 0;
	for(int i=0;i<2*n;i++){
		if(s[i] == 'I'){
			sol += abs(target-i);
			target += 2;
		}
	}
	cout<<sol<<"\n";
}

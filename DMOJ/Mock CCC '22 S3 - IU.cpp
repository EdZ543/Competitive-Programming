#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>s;
	long long tdist = 0, dist = 1;
	for(int i=0;i<2*n;i++){
		if(s[i] == 'I'){
			tdist += abs(1-dist);
			dist = 0;
		}else{
			dist++;
		}
	}
	tdist += abs(1-dist);

	cout<<(tdist%2==0?tdist/2:tdist/2+1)<<"\n";
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	double p;
	cin>>n>>p;

	double happy = 1;
	while(n){
		if(n%2==1) happy = happy*(1-p)+(1-happy)*p;
		p = p*(1-p)+(1-p)*p;
		n /= 2;
	}

	cout<<setprecision(6)<<happy;
}

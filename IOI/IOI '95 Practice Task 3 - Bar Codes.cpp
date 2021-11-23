#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k, m, s; cin >> n >> k >> m >> s;
	for(int i=0;i<s;i++){
		string code; cin >> code;
	}

	vector<int> bars(k);
	int left = n;
	for(int i=0;i<k;i++){
		bars[i] = max(1, left-m*(k-i));
		left -= bars[i];
	}


}

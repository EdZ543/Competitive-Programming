#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int slow_lis(vector<int> a){
	vector<int> dp(a.size(), 1);
	int ret = 1;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<i;j++) if(a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
		ret = max(ret, dp[i]);
	}
	return ret;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		a.push_back(x);
	}

	cout<<slow_lis(a);
}

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

int fast_lis(vector<int> a){
	vector<int> dp;
	for (int i : a) {
		int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (pos == dp.size())  // we can have a new, longer increasing subsequence!
			dp.push_back(i);
		else  // oh ok, at least we can make the ending element smaller
			dp[pos] = i;
	}
	return dp.size();
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		a.push_back(x);
	}

	cout<<fast_lis(a);
}

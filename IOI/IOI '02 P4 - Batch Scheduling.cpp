#include <bits/stdc++.h>
using namespace std;

int n, s;
int dp[10001];
int t[10001], f[10001];
int sumt[10001], sumf[10001];

double x(int j, int k){
	return (double)(dp[j]-dp[k])/(sumt[j]-sumt[k]);
}

int main(){
	cin >> n >> s;
	for(int i=0;i<n;i++) cin >> t[i] >> f[i];
	for(int i=n-1;i>=0;i--) sumt[i] = t[i]+sumt[i+1];	
	for(int i=n-1;i>=0;i--) sumf[i] = f[i]+sumf[i+1];	

	deque<int> dq;
	dq.push_back(n);

	for(int i=n-1;i>=0;i--){
		while(dq.size() >= 2 && x(dq[0], dq[1]) < sumf[i]) dq.pop_front();

		int j = dq.front();
		dp[i] = (dp[j]+(s+sumt[i]-sumt[j])*sumf[i]);

		while(dq.size() >= 2 && x(dq[dq.size()-2], dq[dq.size()-1]) > x(dq[dq.size()-1], i)) dq.pop_back();

		dq.push_back(i);
	}

	cout << dp[0];
}

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

void add_self(int& a, int b){
	a += b;
	if(a >= mod) a -= mod;
}

void sub_self(int&a, int b){
	a -= b;
	if(a < 0) a += mod;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin>>n>>k;

	vector<int> dp(k+1, 0);
	dp[0] = 1;

	for(int child=0;child<n;child++){
		int limit; cin>>limit; // max number of candies for this child
		vector<int> pref(k+1, 0);
		for(int used=k;used>=0;used--){// used: number of candies total being used
			int temp = dp[used]; // number of ways to distribute these candies
			int l = used+1; // number of candies plus one
			int r = used+min(limit, k-used); // min of limit, and number of candies not being used rn
			if(l <= r){
				add_self(pref[l], temp);
				if(r+1 <= k){
					sub_self(pref[r+1], temp);
				}
			}
		}	
		int cur = 0;
		for(int i=0;i<=k;i++){
			add_self(cur, pref[i]);
			add_self(dp[i], cur);
		}
	}

	cout<<dp[k];
}

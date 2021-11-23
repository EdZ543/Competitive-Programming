#include <bits/stdc++.h>
using namespace std;

int q, m, k;
int field_sum = 0, sol;
int field[2000], strip[2000];
bool dp[150001];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>q>>m>>k;
	for(int i=0;i<m;i++){
		cin>>field[i];
		field_sum += field[i];
	}
	for(int i=0;i<k;i++) cin>>strip[i];

	if(field_sum == q) sol = q;
	else if(field_sum < q){
		sort(strip, strip+k);
		int i;
		for(i=0;i<k&&field_sum<q;i++) field_sum += strip[k-i-1];
		sol = q-i;
	}else if(field_sum > q){
		dp[0] = true;
		int k = 0;
		for(int i=0;i<m&&!dp[q];i++){
			for(int j=k;j>=0;j--){
				if(dp[j]) dp[j+field[i]] = true;
			}
			if(k < q) k += field[i];
		}
		sol = q-!dp[q];
	}

	cout<<sol;
}

#include <bits/stdc++.h>
using namespace std;

int a, b, n;
vector<int> hotels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
vector<long long> dp(10000, -1);

long long ways(int v){
	if(hotels[v] == 7000) return 1;
	if(dp[v] != -1) return dp[v];
	int u = v+1;
	long long ret = 0;
	while(u < hotels.size()){
		int dist = hotels[u]-hotels[v];
		if(dist < a){
			u++;
			continue;
		}
		if(dist > b){
			break;
		}
		ret += ways(u);
		u++;
	}
	dp[v] = ret;
	return ret;
}

int main(){
	cin >> a >> b >> n;
	for(int i=0;i<n;i++) {
		int hotel; cin >> hotel;
		hotels.push_back(hotel);
	}

	sort(hotels.begin(), hotels.end());
	
	cout << ways(0) << "\n";
}
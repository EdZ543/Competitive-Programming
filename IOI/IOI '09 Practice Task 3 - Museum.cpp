#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<string, int>> nums;

string revbin(int i){
	string bin = bitset<32>(i).to_string();
	reverse(bin.begin(), bin.end());
	return bin;
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		nums.push_back({revbin(i), i});
	}
	sort(nums.begin(), nums.end());
	for(auto num:nums) cout << num.second << '\n';
}

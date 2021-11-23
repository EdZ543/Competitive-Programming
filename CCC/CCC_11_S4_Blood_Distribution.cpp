#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> units(8);
	vector<int> patients(8);
	for(int i=0;i<8;i++) cin >> units[i];
	for(int i=0;i<8;i++) cin >> patients[i];
	int sol = 0;
	
	// 0 O-
	// 1 O+
	// 2 A-
	// 3 A+
	// 4 B-
	// 5 B+
	// 6 AB-
	// 7 AB+
	vector<vector<int>> doge = {
		{0},
		{1, 0},
		{2, 0},
		{3, 2, 1, 0},
		{4, 0},
		{5, 4, 1, 0},
		{0, 2, 4, 6},
		{1, 0, 3, 2, 5, 4, 7, 6}
	};

	for(int i=0;i<8;i++){
		for(int j=0;j<doge[i].size();j++){
			int patient = i;
			int unit = doge[i][j];
			int oneg = min(units[unit], patients[patient]);
			units[unit] -= oneg;
			patients[patient] -= oneg;
			sol += oneg;
		}
	}

	cout << sol << "\n";
}
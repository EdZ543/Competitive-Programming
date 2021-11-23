#include <bits/stdc++.h>
using namespace std;
#define ll long long

int l, n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> n;
		string list[n];
		map<string, string> parent;
		for (int j = 0; j < n; j++) cin >> list[j];
		parent[list[0]] = list[n-1];
		int maxl = 0;
		int curl = 0;
		for (int j = 0; j < n; j++) {
			if (j == 0) {
				curl++;
				maxl = max(maxl, curl);
			} else if (parent[list[j-1]] == list[j]) {
				curl--;
			} else {
				curl++;
				maxl = max(maxl, curl);
				parent[list[j]] = list[j-1];
			}
		}
		cout << (n*10)-(maxl*20) << "\n";
	}	
}
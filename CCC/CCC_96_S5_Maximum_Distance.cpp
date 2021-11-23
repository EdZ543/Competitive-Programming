#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	for(int i=0;i<t;i++){
		int n; cin >> n;
		vector<int> s1(n), s2(n);
		for(int j=0;j<n;j++) cin >> s1[j];
		for(int j=0;j<n;j++) cin >> s2[j];
		int sol = 0;
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				if(b >= a && s2[b] >= s1[a]) sol = max(sol, b-a);
			}
		}
		cout << "The maximum distance is " << sol << "\n";
	}
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	while(n--){
		string s; cin >> s;
		int sol = 1;
		string t = "";
		for(int i=0;i<s.size();i++){
			t += s[i];
			string reversed = t;
			reverse(reversed.begin(), reversed.end());
			vector<int> prefix_array = prefix_function(reversed);
			int pi_max = *max_element(prefix_array.begin(), prefix_array.end());
			sol += i+1-pi_max;
		}		
		cout << sol << "\n";
	}
}
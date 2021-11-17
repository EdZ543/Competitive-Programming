#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

char convert(string s){
	if(s == "00") return ' ';
	else if(s == "27") return '.';
	else if(s == "28") return ',';
	else if(s == "29") return '!';
	else if(s == "30") return '?';
	else return (char)(stoi(s)+64);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int t=0;t<5;t++){
		int n; cin >> n;
		vector<int> tokens(n);
		for(int i=0;i<n;i++) cin >> tokens[i];

		int key;
		for(int i=100001;i<500000;i+=2){
			if(tokens[0]%i == 0){
				key = i;
				break;
			}
		}
		
		for(int i=0;i<n;i++){
			tokens[i] /= key;
			string s = string(4-to_string(tokens[i]).size(), '0').append(to_string(tokens[i]));
			string a = s.substr(0, 2), b = s.substr(2, 2);
			cout << convert(a) << convert(b);
		}

		cout << "\n";
	}
}
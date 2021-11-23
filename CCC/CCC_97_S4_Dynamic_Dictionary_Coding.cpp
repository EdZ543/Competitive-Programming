#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	cin.ignore();
	for(int i=0;i<n;i++){
		vector<string> dict = {"bruh"};
		while(true){
			string line; getline(cin, line);
			if(line == "") break;
			vector<string> tokens;
			stringstream check(line);
			string intermediate;
			while(getline(check, intermediate, ' ')){
				tokens.push_back(intermediate);
			}

			for(int j=0;j<tokens.size();j++){
				string word = tokens[j];
				auto it = find(dict.begin(), dict.end(), word);
				if(it == dict.end()){
					dict.push_back(word);
					cout << word;
				}else{
					int index = distance(dict.begin(), it);
					cout << index;
				}
				if(j != tokens.size()-1) cout << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}
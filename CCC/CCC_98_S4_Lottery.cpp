#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	cin.ignore();
	for(int i=0;i<n;i++){
		string line; getline(cin, line);
		vector<string> tokens;
		stringstream check(line);
		string intermediate;
		while(getline(check, intermediate, ' ')){
			tokens.push_back(intermediate);
		}
		bool good = true;
		while(good){
			good = false;
			for(int j=0;j<tokens.size();j++){
				if((j-1 != 0 || j+1 != tokens.size()-1) && tokens[j] == "X"){
					string bracketed = "("+tokens[j-1]+" "+tokens[j]+" "+tokens[j+1]+")";
					tokens.erase(tokens.begin()+j-1, tokens.begin()+j+2);
					tokens.insert(tokens.begin()+j-1, bracketed);
					j--;
					good = true;
				}
			}
		}
		good = true;
		while(good){
			good = false;
			for(int j=0;j<tokens.size();j++){
				if((j-1 != 0 || j+1 != tokens.size()-1) && (tokens[j] == "+" || tokens[j] == "-")){
					string bracketed = "("+tokens[j-1]+" "+tokens[j]+" "+tokens[j+1]+")";
					tokens.erase(tokens.begin()+j-1, tokens.begin()+j+2);
					tokens.insert(tokens.begin()+j-1, bracketed);
					j--;
					good = true;
				}
			}
		}
		for(int j=0;j<tokens.size();j++){
			cout << tokens[j];
			if(j != tokens.size()-1) cout << " ";
		}
		if(i != n-1){
			cout << "\n\n";
		}
	}
}
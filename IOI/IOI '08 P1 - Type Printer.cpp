#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> words;
string w;

string ops(vector<string> v){
	string printer = "";
	string ops = "";
	for(int i=0;i<n;i++){
		while(printer != v[i].substr(0, printer.size())){
			printer = printer.substr(0, printer.size()-1);
			ops += "-\n";
		}
		while(printer != v[i]){
			char c = v[i][printer.size()];
			printer += c;
			ops += c;
			ops += '\n';
		}
		ops += "P\n";
	}
	return ops;
}

bool cmp(string a, string b){
	int asame = 0, bsame = 0;
	for(int i=0;i<a.size();i++){
		if(a[i] == w[i]) asame++;
		else break;
	}
	for(int i=0;i<b.size();i++){
		if(b[i] == w[i]) bsame++;
		else break;
	}
	if(asame != bsame) return asame < bsame;
	else return a < b;
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		string word; cin >> word;
		if(word.size() > w.size()) w = word;
		words.push_back(word);
	}

	sort(words.begin(), words.end(), cmp);
	string sol = ops(words);
	cout << sol.size()/2 << '\n' << sol;
}

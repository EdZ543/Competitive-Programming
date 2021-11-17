#include <bits/stdc++.h>
using namespace std;

vector<string> words;

int main(){
	while(true){
		string word; cin >> word;
		if(word == ".") break;
		words.push_back(word);
	}

	vector<string> maxChain;
	vector<int> maxBefore(words.size(), 0);
	for(int i=words.size()-1;i>=0;i--){
		if(maxBefore[i] > 0) continue;
		vector<string> chain = {words[i]};
		int before = 1;
		for(int j=i-1;j>=0;j--){
			if(words[j] == chain.front().substr(0, words[j].size())){
				if(before > maxBefore[j]){
					chain.insert(chain.begin(), words[j]);	
					maxBefore[j] = before;
					before++;
				}else{
					break;
				}
			}
		}
		if(chain.size() > maxChain.size()) maxChain = chain;
	}

	for(auto word:maxChain) cout << word << '\n';
}

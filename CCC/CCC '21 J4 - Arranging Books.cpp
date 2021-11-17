#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin >> s;
	string target = s;
	sort(target.begin(), target.end());
	int lm = 0, ls = 0, ml = 0, ms = 0, sl = 0, sm = 0;
	for(int i=0;i<s.size();i++){
		if(target[i] == 'L'){
			if(s[i] == 'M') lm++;
			else if(s[i] == 'S') ls++;
		}else if(target[i] == 'M'){
			if(s[i] == 'L') ml++;
			else if(s[i] == 'S') ms++;
		}else if(target[i] == 'S'){
			if(s[i] == 'L') sl++;
			else if(s[i] == 'M') sm++;
		}
	}
	int sol = 0;
	int minlm = min(lm, ml);
	sol += minlm;
	lm -= minlm;
	ml -= minlm;
	int minls = min(ls, sl);
	sol += minls;
	ls -= minls;
	sl -= minls;
	int minms = min(ms, sm);
	sol += minms;
	ms -= minms;
	sm -= minms;
	int triplets = lm+ls+ml+ms+sl+sm;
	sol += triplets-triplets/3;
	cout << sol << '\n';
}

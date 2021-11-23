#include <bits/stdc++.h>
using namespace std;

int main(){
	while(true){
		int states, cands; cin >> states >> cands;
		if(states == 0 && cands == 0) break;

		vector<int> def(cands+1, 0), pos(cands+1, 0), tot(cands+1, 0);

		for(int i=0;i<states;i++){
			int scands; cin >> scands;
			for(int j=0;j<scands;j++){
				int cand; cin >> cand;
				if(scands == 1){
					def[cand]++;
				}else{
					pos[cand]++;
				}
				tot[cand]++;
			}
		}
		
		vector<int> maxtots = tot, maxdefs = def;
		for(int i=1;i<=cands;i++){
			vector<int> newtot = tot, newdef = def;
			newtot.erase(newtot.begin()+i);
			newdef.erase(newdef.begin()+i);
			int maxtot = *max_element(newtot.begin(), newtot.end());
			int maxdef = *max_element(newdef.begin(), newdef.end());
			cout << "Candidate " << i << ' ';
			if(def[i] > maxtot){
				cout << "will ";
			}else if(def[i] <= maxtot && tot[i] > maxdef){
				cout << "may ";
			}else if(tot[i] <= maxdef){
				cout << "will not ";
			}
			cout << "become president.\n";
		}

		cout << '\n';
	}
}

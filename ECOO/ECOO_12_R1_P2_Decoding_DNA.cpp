#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

string comp(string s){
	string ret;
	for(int i=0;i<s.size();i++){
		if(s[i] == 'A') ret += 'T';
		else if(s[i] == 'T') ret += 'A';
		else if(s[i] == 'C') ret += 'G';
		else ret += 'C';
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int t=1;t<=5;t++){
		string s; cin >> s;
		int pr = s.find("TATAAT");
		int end;
		bool good = false;
		for(int i=pr+11;i<s.size();i++){
			for(int j=6;i+j<=s.size();j++){
				string sub = s.substr(i, j);
				reverse(all(sub));
				int found = s.find(comp(sub));
				if(found != string::npos && found > i+j){
					end = i;
					good = true;
					break;
				}
			}
			if(good) break;
		}
		string tr = s.substr(pr+10, end-pr-10);
		tr = comp(tr);
		for(int i=0;i<tr.size();i++){
			if(tr[i] == 'T') tr[i] = 'U';
		}
		cout << t << ": " << tr << "\n";
	} 
}
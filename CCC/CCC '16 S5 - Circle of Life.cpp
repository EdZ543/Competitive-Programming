#include <bits/stdc++.h>
using namespace std;

int n;
long long t;
string cells;
vector<string> cycles;

int loop(int x){
	if(x == -1) return n-1;
	if(x == n) return 0;
	return x;
}

void step(){
	string ncells = cells;
	for(int i=0;i<n;i++){
		int nei = 0;
		if(cells[loop(i-1)] == '1') nei++;
		if(cells[loop(i+1)] == '1') nei++;
		if(nei == 1) ncells[i] = '1';
		else ncells[i] = '0';
	}
	cells = ncells;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t >> cells;
	cycles.push_back(cells);
	for(long long i=1;i<=t;i++){
		step();
		auto it = find(cycles.begin(), cycles.end(), cells);
		if(it != cycles.end()){
			long long at = it-cycles.begin();
			long long cl = i-at;
			long long sfc = t-at+1;
			long long co = cl-(sfc%cl);
			long long ret = i-1-co;
			cells = cycles[ret];
			break;
		}
		cycles.push_back(cells);
	}
	cout << cells;
}

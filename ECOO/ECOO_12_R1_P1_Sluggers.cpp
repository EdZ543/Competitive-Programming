#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

string dound(double s){
	stringstream bruh;
	bruh << setprecision(3) << fixed << s;
	return bruh.str().substr(1, 4);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string top; getline(cin, top);
	double batting_all = 0, slugging_all = 0, all_bats = 0;
	cout << top << "\n";
	cout << "====================\n";
	for(int i=0;i<10;i++){
		string name; cin >> name;
		double games_played, at_bats, runs, hits, two_base_hits, three_base_hits, home_runs; cin >> games_played >> at_bats >> runs >> hits >> two_base_hits >> three_base_hits >> home_runs;
		double batting = hits/at_bats;
		double slugging = ((hits-two_base_hits-three_base_hits-home_runs)+2*two_base_hits+3*three_base_hits+4*home_runs)/at_bats;
		batting_all += hits;
		slugging_all += ((hits-two_base_hits-three_base_hits-home_runs)+2*two_base_hits+3*three_base_hits+4*home_runs);
		all_bats += at_bats;
		cout << name << ": " << dound(batting) << " " << dound(slugging) << "\n";
	}
	cout << "====================\n";
	cout << "Big 10 Av: " << dound(batting_all/all_bats) << " " << dound(slugging_all/all_bats);
}
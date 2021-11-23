#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

int scoring(string s){
	if(s.size() == 3 || s.size() == 4) return 1;
	else if(s.size() == 5) return 2;
	else if(s.size() == 6) return 3;
	else if(s.size() == 7) return 4;
	else if(s.size() >= 8) return 11;
	return 0;
}

bool found(vector<string> board, string s, int i, int j, vector<vector<bool>> visited){
	if(s.size() == 0) return true;
	visited[i][j] = true;
	vector<pair<int, int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
	for(auto dir:dirs){
		if(i+dir.fi >= 0 && i+dir.fi <= 3 && j+dir.se >= 0 && j+dir.se <= 3 && !visited[i+dir.fi][j+dir.se] && board[i+dir.fi][j+dir.se] == s[0] && found(board, s.substr(1, s.size()-1), i+dir.fi, j+dir.se, visited)) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int t=0;t<5;t++){
		vector<string> board(4);
		int g_num = 0, sh_num = 0, rep_num = 0, nf_num = 0;
		int score = 0;
		set<string> hist;
		for(int i=0;i<4;i++) cin >> board[i];
		int n; cin >> n;
		for(int i=0;i<n;i++){
			string s; cin >> s;
			// int ilcount = 0;
			// bool sh = false, rep = false, nf = false;
			// if(s.size() < 3){
			// 	sh = true;
			// 	ilcount++;
			// }
			// if(hist.find(s) != hist.end()){
			// 	rep = true;
			// 	ilcount++;
			// }
			// bool founded = false;
			// for(int i=0;i<4;i++){
			// 	for(int j=0;j<4;j++){
			// 		vector<vector<bool>> visited(4, vector<bool>(4, false));
			// 		if(s.size() != 0 && board[i][j] == s[0] && found(board, s.substr(1, s.size()-1), i, j, visited)){
			// 			founded = true;
			// 			break;
			// 		}
			// 	}
			// 	if(founded) break;
			// }
			// if(!founded){
			// 	nf = true;
			// 	ilcount++;
			// }
			// if(sh || ilcount >= 2) sh_num++;
			// else if(rep) rep_num++;
			// else if(nf) nf_num++;
			// else g_num++, score += scoring(s);

			bool founded = false;
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					vector<vector<bool>> visited(4, vector<bool>(4, false));
					if(s.size() != 0 && board[i][j] == s[0] && found(board, s.substr(1, s.size()-1), i, j, visited)){
						founded = true;
						break;
					}
				}
				if(founded) break;
			}
			if(s.size() < 3) sh_num++;
			else if(hist.find(s) != hist.end()) rep_num++;
			else if(!founded) nf_num++;
			else g_num++, score += scoring(s);
			hist.insert(s);
		}
		cout << "Your score: " << score << " (" << g_num << " good, " << nf_num << " not found, " << sh_num << " too short, " << rep_num << " repeated)\n"; 
	}
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, r, c, pr, pc, kr, kc;
int win = -1, stale = -1, loss = -1;
vector<pair<int, int>> khops = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
vector<vector<int>> dp(100, vector<int>(100, -1));

void bfs(){
	queue<pair<int, int>> q;

	dp[kr][kc] = 0;
	q.push({kr, kc});
	int moves = 0;
	int cur_level = 1, next_level = 0;

	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();

		for(auto khop:khops){
			pair<int, int> next = {cur.first+khop.first, cur.second+khop.second};
			if(next.first < 1 || next.first > r || next.second < 1 || next.second > c || dp[next.first][next.second] != -1) continue;
			dp[next.first][next.second] = moves+1;
			q.push(next);
			next_level++;
		}

		cur_level--;
		if(cur_level == 0){
			cur_level = next_level;
			next_level = 0;
			moves++;
		}
	}

	int pmoves = 0;
	int kmoves = 0;
	while(true){
		pmoves++;
		pr++;
		if(pr == r){
			loss = kmoves;
			return;
		}
		kmoves++;
		if(win == -1 && dp[pr][pc] != -1 && dp[pr][pc] <= pmoves && (pmoves-dp[pr][pc])%2 == 0){
			win = kmoves;
			return;
		}else if(stale == -1 && dp[pr+1][pc] != -1 && dp[pr+1][pc] <= pmoves && (pmoves-dp[pr+1][pc])%2 == 0){
			stale = kmoves;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> r >> c >> pr >> pc >> kr >> kc;	
		if(pr == kr-1 && pc == kc){
			cout << "Stalemate in 0 knight move(s).\n";
			continue;
		}
		win = -1;
		stale = -1;
		loss = -1;
		dp.assign(100, vector<int>(100, -1));

		bfs();
		if(win != -1){
			cout << "Win in " << win << " knight move(s).\n";
		}else if(stale != -1){
			cout << "Stalemate in " << stale << " knight move(s).\n";
		}else{
			cout << "Loss in " << loss << " knight move(s).\n";
		}
	}
}
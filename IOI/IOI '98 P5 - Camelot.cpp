#include <bits/stdc++.h>
using namespace std;

int kids[8][8], knds[8][8][8][8];
pair<int, int> ki;
vector<pair<int, int>> kns;
pair<int, int> kndirs[] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

void bfs(int i, int j){
	bool visited[8][8];
	memset(visited, false, sizeof(visited));
	queue<pair<int, pair<int, int>>> bq;
	bq.push({0, {i, j}});
	visited[i][j] = true;

	while(!bq.empty()){
		int cd = bq.front().first;
		int cx = bq.front().second.first;
		int cy = bq.front().second.second;
		bq.pop();
		knds[i][j][cx][cy] = cd;
		for(auto kndir:kndirs){
			int nd = cd+1;
			int nx = cx+kndir.first;
			int ny = cy+kndir.second;
			if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || visited[nx][ny]) continue;
			visited[nx][ny] = true;
			bq.push({nd, {nx, ny}});
		}
	}	
}

int main(){
	string s; cin >> s;
	for(int i=0;i<s.size();i+=2){
		int r = s[i]-'A', c = s[i+1]-'0'-1;
		if(i == 0) ki = {r, c};
		else kns.push_back({r, c});
	}

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			int w = abs(ki.first-i);
			int h = abs(ki.second-j);
			int d = max(w, h);
			kids[i][j] = d;
		}
	}

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			bfs(i, j);
		}
	}

	int sol = INT_MAX;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			int nrsum = 0;
			nrsum += kids[i][j];
			for(auto kn:kns){
				nrsum += knds[kn.first][kn.second][i][j];
			}
			sol = min(sol, nrsum);

			for(int k=0;k<8;k++){
				for(int l=0;l<8;l++){
					for(auto kn:kns){
						int rsum = nrsum-kids[i][j]-knds[kn.first][kn.second][i][j];
						rsum += kids[k][l];
						rsum += knds[kn.first][kn.second][k][l];
						rsum += knds[k][l][i][j];
						sol = min(sol, rsum);
					}
				}
			}
		}
	}

	cout << sol;
}

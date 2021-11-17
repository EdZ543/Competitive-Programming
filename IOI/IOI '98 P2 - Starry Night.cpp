#include <bits/stdc++.h>
using namespace std;

int w, h;
string grid[100];
vector<vector<vector<vector<bool>>>> cls;
bool visited[100][100] = {0};
vector<vector<vector<vector<bool>>>> hello;

vector<pair<int, int>> getclcs(pair<int, int> v){
	memset(visited, 0, sizeof(visited));
	visited[v.first][v.second] = true;
	queue<pair<int, int>> bq;
	bq.push(v);
	vector<pair<int, int>> ret;

	while(!bq.empty()){
		pair<int, int> cur = bq.front();
		bq.pop();
		ret.push_back(cur);
		for(int i=cur.first-1;i<=cur.first+1;i++){
			for(int j=cur.second-1;j<=cur.second+1;j++){
				if(i < 0 || i >= h || j < 0 || j >= w || make_pair(i, j) == cur || grid[i][j] != '1' || visited[i][j]) continue;
				bq.push({i, j});
				visited[i][j] = true;
			}
		}
	}

	return ret;
}

vector<vector<bool>> getcl(vector<pair<int, int>> clcs){
	int minr = INT_MAX, maxr = 0, minc = INT_MAX, maxc = 0;
	for(auto c:clcs){
		minr = min(minr, c.first);
		maxr = max(maxr, c.first);
		minc = min(minc, c.second);
		maxc = max(maxc, c.second);
	}

	vector<vector<bool>> ret(maxr-minr+1, vector<bool>(maxc-minc+1, 0));
	for(auto c:clcs){
		ret[c.first-minr][c.second-minc] = 1;
	}

	return ret;
}

void rotate(vector<vector<bool>> &cl){
	vector<vector<bool>> rotated(cl[0].size(), vector<bool>(cl.size()));
	for(int i=0;i<cl.size();i++){
		for(int j=0;j<cl[i].size();j++){
			int r = j;
			int c = cl.size()-i-1;
			rotated[r][c] = cl[i][j];
		}
	}
	cl = rotated;
}

void addors(vector<vector<bool>> cl){
	cls.push_back(vector<vector<vector<bool>>>());
	for(int i=0;i<4;i++){
		cls.back().push_back(cl);
		rotate(cl);
	}
	reverse(cl.begin(), cl.end());
	for(int i=0;i<4;i++){
		cls.back().push_back(cl);
		rotate(cl);
	}
}

char getle(vector<vector<bool>> cl){
	for(int i=0;i<cls.size();i++){
		for(auto ori:cls[i]){
			if(cl == ori) return 97+i;
		}
	}

	addors(cl);
	return 97+cls.size()-1;
}

int main(){
	cin >> w >> h;
	for(int i=0;i<h;i++) cin >>	grid[i];

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(grid[i][j] != '1') continue;
			vector<pair<int, int>> clcs = getclcs({i, j});
			vector<vector<bool>> cl = getcl(clcs);
			char le = getle(cl);
			for(auto clc:clcs) grid[clc.first][clc.second] = le;
		}
	}

	cout << '\n';
	for(int i=0;i<h;i++) cout << grid[i] << '\n';
}

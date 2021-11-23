#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2000

int n, s;
vector<string> grid;
int bees[MAX_N][MAX_N];
pair<int, int> dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> start, home;

bool surrounded(vector<string> g, int i, int j, char c, int mins){
	int ret = 0;
	if(i != 0 && g[i-1][j] == c && bees[i-1][j] > mins) ret++;
	if(i != n-1 && g[i+1][j] == c && bees[i+1][j] > mins) ret++;
	if(j != 0 && g[i][j-1] == c && bees[i][j-1] > mins) ret++;
	if(j != n-1 && g[i][j+1] == c && bees[i][j+1] > mins) ret++;
	return ret;
}

bool good(int x){
	if(x*s >= bees[start.first][start.second]) return false;

	bool visited[MAX_N][MAX_N];
	memset(visited, false, sizeof(visited));
	visited[start.first][start.second] = true;
	queue<pair<int, pair<int, int>>> bq;
	bq.push({x*s, start});

	while(!bq.empty()){
		int steps = bq.front().first;
		int x = bq.front().second.first;
		int y = bq.front().second.second;
		bq.pop();

		if(grid[x][y] == 'D') return true;

		for(auto dir:dirs){
			int nx = x+dir.first;
			int ny = y+dir.second;

			if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 'T' && steps+1 < bees[nx][ny] && !visited[nx][ny]){
				bq.push({steps+1, {nx, ny}});
				visited[nx][ny] = true;
			}
		}
	}

	return false;
}

int maxBin(int lo, int hi, function<bool(int)> good){
	for(lo--;lo<hi;){
		int mid = lo+(hi-lo+1)/2;
		if(good(mid)) lo = mid;
		else hi = mid-1;
	}
	return lo;
}

void calcBEES(){
	memset(bees, -1, sizeof(bees));
	bees[home.first][home.second] = INT_MAX;
	queue<pair<int, int>> bq;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j] == 'H'){
				bq.push({i, j});
				bees[i][j] = 0;
			}
		}
	}

	while(!bq.empty()){
		pair<int, int> cur = bq.front();
		bq.pop();

		for(auto dir:dirs){
			pair<int, int> next = {cur.first+dir.first, cur.second+dir.second};
			if(next.first >= 0 && next.first < n && next.second >= 0 && next.second < n && grid[next.first][next.second] == 'G' && bees[next.first][next.second] == -1){
				bees[next.first][next.second] = bees[cur.first][cur.second]+s;
				bq.push(next);
			}
		}
	}
}

int main(){
	cin >> n >> s;
	for(int i=0;i<n;i++){
		string s; cin >> s;
		grid.push_back(s);

		for(int j=0;j<n;j++){
			if(s[j] == 'M') start = {i, j}, grid[i][j] = 'G';
			else if(s[j] == 'D') home = {i, j};
		}
	}

	calcBEES();

	cout << maxBin(0, n*n, good);
}

#include <bits/stdc++.h>
using namespace std;

struct Move{
	char c;
	int x, y, z;
};

int l, w, h;
vector<int> dirs[] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

bool canEat(int x, int y, int z, int nx, int ny, int nz, vector<vector<vector<bool>>> eaten){
	for(auto dir:dirs){
		int nnx = nx+dir[0], nny = ny+dir[1], nnz = nz+dir[2];
		if(nnx < 1 || nnx > l || nny < 1 || nny > w || nny < 1 || nny > h || (nnx == x && nny == y && nnz == z) || !eaten[nnx][nny][nnz]) continue;
		return false;
	}
	return true;
}

vector<Move> dfs(int x, int y, int z, vector<vector<vector<bool>>> eaten, vector<vector<vector<bool>>> visited){
	eaten[x][y][z] = true;
	visited[x][y][z] = true;
	vector<Move> ret;
	for(auto dir:dirs){
		int nx = x+dir[0], ny = y+dir[1], nz = z+dir[2];
		if(nx < 1 || nx > l || ny < 1 || ny > w || nz < 1 || nz > h) continue;
		if(!eaten[nx][ny][nz] && canEat(x, y, z, nx, ny, nz, eaten)){
			auto neaten = eaten;
			neaten[nx][ny][nz] = true;
			vector<Move> next = dfs(x, y, z, neaten, visited);
			next.insert(next.begin(), Move{'E', nx, ny, nz});
			if(next.size() > ret.size()) ret = next;
		}
		if(eaten[nx][ny][nz] && !visited[nx][ny][nz]){
			vector<Move> next = dfs(nx, ny, nz, eaten, visited);
			next.insert(next.begin(), Move{'M', nx, ny, nz});
			if(next.size() > ret.size()) ret = next;
		}
	}
	return ret;
}

int main(){
	cin >> l >> w >> h;
	vector<vector<vector<bool>>> empty(l+1, vector<vector<bool>>(w+1, vector<bool>(h+1, false)));
	auto empty2 = empty;
	cout << "E 1 1 1\nM 1 1 1\n";
	for(auto move:dfs(1, 1, 1, empty, empty2)) cout << move.c << ' ' << move.x << ' ' << move.y << ' ' << move.z << '\n';
}

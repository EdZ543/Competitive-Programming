#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> points;
int bestd[2001];
int pbestn[2001];
int bestn[2001];
vector<vector<int>> lines;

int main(){
	cin >> n;
	int count = 0;
	points.push_back({0, 0});
	for(int i=1;i<=n;i++){
		int x, y; cin >> x >> y;
		points.push_back({x, y});
		for(int j=i-1;j>=0;j--){
			lines.push_back({(int)pow(points[i].first-points[j].first, 2)+(int)pow(points[i].second-points[j].second, 2), j, i});
			count++;
		}
	}
	sort(lines.begin(), lines.end());
	for(int i=0;i<count;i++){
		vector<int> next = lines[i];
		if(next[0] > bestd[next[1]]){
			bestd[next[1]] = next[0];
			pbestn[next[1]] = bestn[next[1]];
		}
		if(next[0] > bestd[next[2]]){
			bestd[next[2]] = next[0];
			pbestn[next[2]] = bestn[next[2]];
		}
		if(next[1] == 0){
			bestn[next[1]] = max(bestn[next[1]], pbestn[next[2]]);
		}else{
			bestn[next[1]] = max(bestn[next[1]], pbestn[next[2]]+1);
			bestn[next[2]] = max(bestn[next[2]], pbestn[next[1]]+1);
		}
	}
	cout << bestn[0]+1;
}

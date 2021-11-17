#include <bits/stdc++.h>
using namespace std;

int mina = INT_MAX;
set<pair<int, int>> sols;
pair<int, int> rects[4];

void trydims(int lay, pair<int, int> rs[4]){
	int a, b;
	if(lay == 0){
		a = rs[0].first+rs[1].first+rs[2].first+rs[3].first;
		b = max({rs[0].second, rs[1].second, rs[2].second, rs[3].second});
	}else if(lay == 1){
		a = max(rs[0].first+rs[1].first+rs[2].first, rs[3].first);
		b = max({rs[0].second, rs[1].second, rs[2].second})+rs[3].second;
	}else if(lay == 2){
		a = max(rs[0].first+rs[1].first, rs[3].first)+rs[2].first;
		b = max(max(rs[0].second, rs[1].second)+rs[3].second, rs[2].second);
	}else if(lay == 3){
		a = rs[0].first+max(rs[1].first, rs[2].first)+rs[3].first;
		b = max({rs[0].second, rs[1].second+rs[2].second, rs[3].second});
	}else if(lay == 4){
		a = max(rs[0].first, rs[1].first)+rs[2].first+rs[3].first;
		b = max({rs[0].second+rs[1].second, rs[2].second, rs[3].second});
	}else if(lay == 5){
		a = max({rs[0].first+rs[2].first, rs[1].first+rs[3].first, rs[0].first+rs[3].first});
		b = max({rs[0].second+rs[1].second, rs[2].second+rs[3].second, rs[1].second+rs[2].second});
	}
	int area = a*b;
	//if(area == 36){
	//	for(int i=0;i<4;i++){
	//		cout << rs[i].first << ' ' << rs[i].second << '\n';
	//	}
	//	cout << '\n';
	//}
	pair<int, int> sol = {min(a, b), max(a, b)};
	if(area < mina){
		mina = area;
		sols.clear();
		sols.insert(sol);
	}else if(area == mina){
		sols.insert(sol);
	}
}

void combs(int ind, int lay, pair<int, int> rs[4], bool used[4]){
	if(ind == 4){
		trydims(lay, rs);
	}else{
		for(int i=0;i<4;i++){
			if(used[i]) continue;
			used[i] = true;
			rs[ind] = rects[i];
			combs(ind+1, lay, rs, used);
			swap(rs[ind].first, rs[ind].second);
			combs(ind+1, lay, rs, used);
			used[i] = false;
		}
	}	
}

int main(){
	for(int i=0;i<4;i++) cin >> rects[i].first >> rects[i].second;

	for(int i=0;i<6;i++){
		pair<int, int> rs[4];
		bool used[4] = {0};
		combs(0, i, rs, used);
	}
	
	cout << mina << '\n';
	for(auto sol:sols){
		cout << sol.first << ' ' << sol.second << '\n';
	}
}

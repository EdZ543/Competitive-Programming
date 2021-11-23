#include <bits/stdc++.h>
using namespace std;

int v, p;
int vils[300];
int distdp[300][300];
vector<int> seqdp[300][300];

void dfs(int vil, int post){
	if(distdp[vil][post] != -1) return;

	int disret = INT_MAX;
	vector<int> seqret;

	if(post == p){
		disret = 0;
		for(int i=vil;i<v;i++) disret += vils[i]-vils[vil-1];
	}else{
		for(int i=vil;i<=v-(p-post);i++){
			dfs(i+1, post+1);
			int dis = distdp[i+1][post+1];
			vector<int> seq = seqdp[i+1][post+1];
			seq.insert(seq.begin(), vils[i]);
			if(vil == 0) for(int j=vil;j<i;j++) dis += vils[i]-vils[j];
			else for(int j=vil;j<i;j++) dis += min(vils[j]-vils[vil-1], vils[i]-vils[j]);
			if(dis < disret){
				disret = dis;
				seqret = seq;
			}
		}
	}

	distdp[vil][post] = disret;
	seqdp[vil][post] = seqret;	
}

int main(){
	cin >> v >> p;
	for(int i=0;i<v;i++) cin >> vils[i];

	memset(distdp, -1, sizeof(distdp));
	dfs(0, 0);
	cout << distdp[0][0] << '\n';
	for(auto vil:seqdp[0][0]) cout << vil << ' ';
}

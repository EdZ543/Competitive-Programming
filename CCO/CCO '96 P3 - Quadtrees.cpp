#include <bits/stdc++.h>
using namespace std;

int n;

void paint(vector<vector<bool>> &grid, string s, int v, int l, int r, int t, int b, vector<bool> &vis){
	vis[v] = true;
	if(s[v] == 'f'){
		for(int i=t;i<b;i++){
			for(int j=l;j<r;j++){
				grid[i][j] = true;
			}
		}
	}else if(s[v] == 'p'){
		int quad = 1;
		for(int u=v+1;u<s.size();u++){
			if(!vis[u]){
				if(quad == 1) paint(grid, s, u, (l+r)/2, r, t, (t+b)/2, vis);
				else if(quad == 2) paint(grid, s, u, l, (l+r)/2, t, (t+b)/2, vis);
				else if(quad == 3) paint(grid, s, u, l, (l+r)/2, (t+b)/2, b, vis);
				else if(quad == 4) paint(grid, s, u, (l+r)/2, r, (t+b)/2, b, vis);
				else break;
				quad++;
			}
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	while(n--){
		string a, b;
		cin>>a>>b;

		vector<bool> vis1(a.size(), false), vis2(b.size(), false);
		vector<vector<bool>> im1(32, vector<bool>(32, false)), im2(32, vector<bool>(32, false));
		paint(im1, a, 0, 0, 32, 0, 32, vis1);
		paint(im2, b, 0, 0, 32, 0, 32, vis2);

		int pixels = 0;
		for(int i=0;i<32;i++){
			for(int j=0;j<32;j++){
				pixels += im1[i][j] || im2[i][j];
			}
		}

		cout<<"There are "<<pixels<<" black pixels.\n";
	}
}

#include <bits/stdc++.h>
using namespace std;

struct ST{
	int n, k;
	vector<int> lg;
	vector<vector<int>> st;

	ST(vector<int> a){
		n = a.size();
		k = floor(log2(n));

		lg.resize(n+1);
		st.resize(n, vector<int>(k+1));

		lg[1] = 0;
		for(int i=2;i<=n;i++) lg[i] = lg[i/2]+1;

		for(int i=0;i<n;i++) st[i][0] = a[i];

		for(int j=1;j<=k;j++){
			for (int i=0;i+(1<<j)<=n;i++){
				st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
			}
		}
	}

	int min_query(int l, int r){
		int j = lg[r-l+1];
		return min(st[l][j], st[r-(1<<j)+1][j]);
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q; cin >> N >> Q;
	vector<int> a(N);
	for(int i=0;i<N;i++) cin >> a[i];
	ST st(a);
	while(Q--){
		int l, r; cin >> l >> r;
		cout << st.min_query(l, r-1) << "\n";
	}
}

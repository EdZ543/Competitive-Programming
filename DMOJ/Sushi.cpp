#include <bits/stdc++.h>
using namespace std;

const int MAXN = 301;
double dp[MAXN][MAXN][MAXN], ev[MAXN][MAXN][MAXN];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n; cin>>n;
	vector<int> cnt(4, 0);
	for(int i=0;i<n;i++){
		int x; cin>>x;
		cnt[x]++;
	}	

	dp[cnt[1]][cnt[2]][cnt[3]] = 1;
	for(int c=n;c>=0;c--){
		for(int b=n;b>=0;b--){
			for(int a=n;a>=0;a--){
				if(a+b+c == 0) continue;
				if(a+b+c > n) continue;

				double p_waste = (double)(n-(a+b+c))/n;
				double ev_waste = (double)p_waste/(1-p_waste)+1;
				ev[a][b][c] += ev_waste*dp[a][b][c];

				if(a != 0){
					double p = (double)a/(a+b+c);
					dp[a-1][b][c] += dp[a][b][c]*p;
					ev[a-1][b][c] += ev[a][b][c]*p;
				}
				if(b != 0){
					double p = (double)b/(a+b+c);
					dp[a+1][b-1][c] += dp[a][b][c]*p;
					ev[a+1][b-1][c] += ev[a][b][c]*p;
				}
				if(c != 0){
					double p = (double)c/(a+b+c);
					dp[a][b+1][c-1] += dp[a][b][c]*p;
					ev[a][b+1][c-1] += ev[a][b][c]*p;
				}
			}
		}
	}

	cout<<setprecision(100)<<ev[0][0][0];
}

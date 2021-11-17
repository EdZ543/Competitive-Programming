#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;

int n, q;
int score[MAXN];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>score[i];

	while(q--){
		int l, r; cin>>l>>r;
		int mfreq = 0, mscore = -1;
		int freq[n+1] = {0};
		for(int i=l;i<=r;i++){
			freq[score[i]]++;
			if(freq[score[i]] > mfreq || (freq[score[i]] == mfreq && score[i] > mscore)){
				mfreq = freq[score[i]];
				mscore = score[i];
			}
		}
		cout<<mscore<<"\n";
	}
}

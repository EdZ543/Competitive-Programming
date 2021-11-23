#include <bits/stdc++.h>
using namespace std;

int N, L, M;

struct B{
	vector<int> es;
	vector<int> js;
	vector<int> last;

	int J(int e){
		return js[e];
	}

	int T(int e){
		return es[es.size()-1-last[e]]+L;
	}

	int mine(int x){
		int l = 0, r = es.size();
		for(r++;l<r;){
			int m = l+(r-l)/2;
			if(es[m] > x) r = m;
			else l = m+1;
		}
		return r;
	}

	void proc(){
		es.push_back(es.back()+L+1);
		int t = es.size()-1;
		js.assign(es.size(), 0);
		last.assign(es.size(), 0);
		js[es.size()-1] = 0;
		last[es.size()-1] = es.size()-1;
		for(int j=es.size()-2;j>=0;j--){
			while(es[t-1] > es[j]+L) t--;
			js[j] = js[t]+1;
			last[j] = last[t];	
			if(last[j] == es.size()-1) last[j] = j;
		}
		es.pop_back();
	}
};

int eps[150000];
vector<B> bs;
int k;

void update(int a, int b){
	for(int i=0;i<bs.size();i++){
		if(bs[i].es[0] < eps[a] && eps[a] < bs[i].es.back()){
			bs[i].es.insert(upper_bound(bs[i].es.begin(), bs[i].es.end(), eps[a]), eps[a]);
			bs[i].proc();
		}
		if(bs[i].es[0] < b && b < bs[i].es.back()){
			bs[i].es.insert(upper_bound(bs[i].es.begin(), bs[i].es.end(), b), b);
			bs[i].proc();
		}
	}
	eps[a] = b;
}

int cams(){
	int ret = 0;
	int e = 0;
	for(int i=0;i<bs.size();i++){
		ret += bs[i].J(e);
		if(i != bs.size()-1) e = bs[i+1].mine(bs[i].T(e));
	}
	return ret;
}

void build(){
	bs.clear();
	B b;
	bs.push_back(b);
	for(int i=0;i<N;i++){
		if(bs.back().es.size() >= N/k){
			B b;
			bs.push_back(b);
		}		
		bs.back().es.push_back(eps[i]);
	}
}

int main(){
	cin >> N >> L >> M;
	k = sqrt(N);
	for(int i=0;i<N;i++) cin >> eps[i];
	
	for(int i=0;i<M;i++){
		if(i % (int)ceil(N/k) == 0) build();
		int a, b; cin >> a >> b;
		update(a, b);
		cout << cams() << '\n';
	}
}

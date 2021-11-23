#include <bits/stdc++.h>
using namespace std;

vector<int> query(string q){
	cout<<q<<endl;
	vector<int> ret(10);
	int k; cin>>k;
	for(int i=0;i<k;i++){
		string s; cin>>s;
		for(int j=0;j<s.size();j++) ret[s[j]-'0'] = i;
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	while(1){
		query("next 0 1");
		vector<int> group = query("next 1");
		if(group[0] == group[1]) break;	
	}

	while(1){
		vector<int> group = query("next 0 1 2 3 4 5 6 7 8 9");
		if(group[0] == group[2]) break;
	}
	cout<<"done"<<endl;
}

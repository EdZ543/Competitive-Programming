#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct section{
	int a = 0, b = 0, c = 0;
	void add(char e){
		if(e == 'A') a++;
		else if(e == 'B') b++;
		else if (e == 'C') c++;
	}
	void remove(char e){
		if(e == 'A') a--;
		else if(e == 'B') b--;
		else if (e == 'C') c--;
	}
};

int solve(string s){
	int n = s.size()/2;
	section total;
	for(int i=0;i<n;i++){
		total.add(s[i]);
	}

	section a, b, c;
	for(int i=0;i<total.a;i++){
		a.add(s[i]);
	}
	for(int i=total.a;i<total.a+total.b;i++){
		b.add(s[i]);		
	}
	for(int i=total.a+total.b;i<total.a+total.b+total.c;i++){
		c.add(s[i]);
	}

	int sol = INT_MAX;
	for(int i=0;i<n;i++){
		int swaps = a.b+a.c+b.a+b.c-min(a.b, b.a);
		sol = min(sol, swaps);
		a.remove(s[i]);
		a.add(s[i+total.a]);
		b.remove(s[i+total.a]);
		b.add(s[i+total.a+total.b]);
		c.remove(s[i+total.a+total.b]);
		c.add(s[i+total.a+total.b+total.c]);
	}

	return sol;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s; cin >> s;
	s += s;

	string s2 = s;
	for(int i=0;i<s2.size();i++){
		if(s2[i] == 'A') s2[i] = 'C';
		else if(s2[i] == 'C') s2[i] = 'A';
	}

	cout << min(solve(s), solve(s2));
}
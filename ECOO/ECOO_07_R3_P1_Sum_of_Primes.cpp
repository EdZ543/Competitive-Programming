#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

bool prime(int n){
	if(n == 2) return false;
	if(n <= 1) return false;
	if(n <= 3) return true;
	if(n % 2 == 0 || n % 3 == 0) return false;
	for(int i=5;i*i<=n;i+=6){
		if(n%i == 0 || n%(i+2) == 0) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 5;
	while(t--){
		int n; cin >> n;
		if(prime(n)){
			cout << n << " = " << n << "\n";
			continue;
		}
		bool good = false;
		for(int i=n/2;i>2;i-=(i%2==0)?1:2){
			int j = n-i;
			if(prime(i) && prime(j)){
				good = true;
				cout << n << " = " << i << " + " << j << "\n";
				break;
			}
		}
		if(!good){
			bool done = false;
			for(int i=n/3;i>2;i-=(i%2==0)?1:2){
				for(int j=(n-i)/2;j>=i;j-=(j%2==0)?1:2){
					int k = n-i-j;
					if(prime(i) && prime(j) && prime(k)){
						cout << n << " = " << i << " + " << j << " + " << k << "\n";
						done = true;
						break;
					}
				}
				if(done) break;
			}
		}
	}
}
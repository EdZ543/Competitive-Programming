#include <bits/stdc++.h>
using namespace std;

bool good(int n, int w, int h, int wi, int he){
	int bruh = lcm(w, h);
	if((wi % w == 0 && he % h == 0) || (wi % h == 0 && he % w == 0)){
		return true;
	}

	if(wi % bruh == 0){
		for(int i=1;i<=he/h;i++){
			if((he-i*h) % w == 0){
				return true;
			}
		}
	}

	return false;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int c; cin>>c;

	while(c--){
		int n, w, h; cin>>n>>w>>h;
		int area = n*w*h;
		
		for(int i=ceil(sqrt(area));i>=1;i--){
			if(area % i == 0){
				int j = area/i;
				if(good(n, w, h, i, j) || good(n, w, h, j, i)){
					cout<<2*(i+j)<<"\n";
					break;
				}
			}
		}
	}
}

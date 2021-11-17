#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	vector<pair<double, double>> cookies(n);
	for(int i=0;i<n;i++) cin >> cookies[i].first >> cookies[i].second;
	double sol = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				double a = sqrt(pow(cookies[i].first-cookies[j].first, 2)+pow(cookies[i].second-cookies[j].second, 2));
				double b = sqrt(pow(cookies[j].first-cookies[k].first, 2)+pow(cookies[j].second-cookies[k].second, 2));
				double c = sqrt(pow(cookies[k].first-cookies[i].first, 2)+pow(cookies[k].second-cookies[i].second, 2));
				double semiP = (a+b+c)/2;
				double diameter = 0;
				double tri1 = pow(a, 2)+pow(b, 2)-pow(c, 2);
				double tri2 = pow(b, 2)+pow(c, 2)-pow(a, 2);
				double tri3 = pow(a, 2)+pow(c, 2)-pow(b, 2);
				if(tri1 < 0 || tri2 < 0 || tri3 < 0 || semiP == 0){
					diameter = max(diameter, a);
					diameter = max(diameter, b);
					diameter = max(diameter, c);
				}else{
					diameter = (a*b*c);
					diameter /= (4*sqrt(semiP*(semiP-a)*(semiP-b)*(semiP-c)));
					diameter *= 2;
				}
				sol = max(sol, diameter);	
			}
		}
	}
	cout << fixed << setprecision(2) << sol << "\n";
}
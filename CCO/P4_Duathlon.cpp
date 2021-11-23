#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<pair<double, double>> comps;
pair<double, double> cheater;

double getMargin(double r, double k){
    double minComp = INT_MAX;
    for(int i=0;i<n-1;i++){
        double speed = r/comps[i].first+k/comps[i].second;
        minComp = min(minComp, speed);
    }
    double cheaterSpeed = r/cheater.first+k/cheater.second;
    return minComp-cheaterSpeed;
}

int main(){
    cin >> t >> n;
    for(int i=0;i<n-1;i++){
        double a, b; cin >> a >> b;
        comps.push_back({a, b});
    }
    cin >> cheater.first >> cheater.second;

    double maxTime = 0, maxR = 0, maxK = 0;
    for(double r=0;r<=t;r+=0.01){
        double k = t-r;
        double winMargin = getMargin(r, k);
        if(winMargin > maxTime){
            maxTime = winMargin;
            maxR = r;
            maxK = k;
        }
    }

    if(maxTime > 0){
        cout << fixed << setprecision(0) << "The cheater can win by " << maxTime*60*60 << " seconds with r = " << setprecision(2) << maxR << "km and k = " << maxK << "km.\n";
    }else{
        cout << "The cheater cannot win.\n";
    }
}
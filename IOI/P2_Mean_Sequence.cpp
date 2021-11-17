#include <bits/stdc++.h>
using namespace std;

int r(int a, int c){
    return 2*c-a;
}

int main(){
    int n; cin >> n;

    pair<int, int> range = {-1000000000, 1000000000};
    for(int i=0;i<n;i++){
        int avg; cin >> avg;
        int a, b; tie(a, b) = range;
        range = {r(min(b, avg), avg), r(a, avg)};
    }
    cout << max(0, range.second-range.first+1);
}
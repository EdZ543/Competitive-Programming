#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int start, interval, message; cin >> start >> interval >> message;
    for(int i=0;i<3;i++){
        start += interval;
        if(start >= message){
            cout << start;
            return 0;
        }
    }
    cout << "Who knows...";
}
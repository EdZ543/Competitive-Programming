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
    
    int n, m, k; cin >> n >> m >> k;
    vector<int> scores(n+1, -1);
    vector<int> profs(n+1, -1);
    for(int i=0;i<k;i++){
        int a, b, c; cin >> a >> b >> c;
        if(c > scores[b]){
            scores[b] = c;
            profs[b] = a;
        }
    }
    for(int i=1;i<=n;i++) cout << profs[i] << " ";
}
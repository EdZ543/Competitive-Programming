#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rs = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};
int dp[31][31][31][31] = {0};

string winar(int a, int b, int c, int d, string turn, string not_turn){
    if(dp[a][b][c][d] != 0) return dp[a][b][c][d] == 1 ? turn : not_turn;
    for(auto r:rs){
        if(a-r[0] >= 0 && b-r[1] >= 0 && c-r[2] >= 0 && d-r[3] >= 0 && winar(a-r[0], b-r[1], c-r[2], d-r[3], not_turn, turn) == turn){
            dp[a][b][c][d] = 1;
            return turn;
        }
    }
    dp[a][b][c][d] = 2;
    return not_turn;
}

int main(){
    int t; cin >> t;
    while(t--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << winar(a, b, c, d, "Patrick", "Roland") << "\n";
    }
}
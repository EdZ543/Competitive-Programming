#include <bits/stdc++.h>
using namespace std;

int m, n, k;

bool in_range(int r, int c){
    return r >= 1 && r <= m && c >= 1 && c <= n;
}

int main(){
    cin >> m >> n >> k;

    vector<vector<int>> grid(m+1, vector<int>(n+1, 0));
    for(int i=0;i<k;i++){
        int x, y, r, b; cin >> x >> y >> r >> b;

        for(int j = max(1, y-r);j<=min(m, y+r);j++){
            int left = max(1, x-(int)sqrt(pow(r, 2)-pow(y-j, 2)));
            int right = min(n, x+(int)sqrt(pow(r, 2)-pow(y-j, 2)));
            grid[j][left] += b;
            if(right+1 <= n) grid[j][right+1] -= b;
        }
    }

    int maxb = 0;
    int sol = 0;
    for(int i=1;i<=m;i++){
        int sum = 0;
        for(int j=1;j<=n;j++){
            sum += grid[i][j];
            if(sum == maxb) sol++;
            else if(sum > maxb){
                maxb = sum;
                sol = 1;
            }
        }
    }

    cout << maxb << "\n" << sol;
}
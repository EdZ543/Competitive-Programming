#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int rows, cols; cin >> rows >> cols;
        if(rows == 0 && cols == 0) break;

        int grid[rows][cols];
        for(int i=0;i<rows;i++){
            string line; cin >> line;
            for(int j=0;j<cols;j++){
                if(line[j] == '.') grid[i][j] = 0;
                else if(line[j] == '*') grid[i][j] = -1;
                else grid[i][j] = line[j]-'0';
            }
        }
        
        vector<vector<int>> money(rows, vector<int>(cols, -1));

        money[rows-1][0] = grid[rows-1][0];
        for(int i=rows-2;i>=0;i--){
            if(grid[i][0] >= 0){
                if(grid[i][0] >= 0) money[i][0] = money[i+1][0] + grid[i][0];
                else break;
            }
        }

        for(int c=1;c<cols;c++){
            for(int r=0;r<rows;r++){
                if(money[r][c-1] >= 0){
                    int t = money[r][c-1];
                    for(int k=r;k<rows;k++){
                        if(grid[k][c] >= 0){
                            t += grid[k][c];
                            money[k][c] = max(money[k][c], t);
                        }else{
                            break;
                        }
                    }
                }
            }
            for(int r=rows-1;r>=0;r--){
                if(money[r][c-1] >= 0){
                    int t = money[r][c-1];
                    for(int k=r;k>=0;k--){
                        if(grid[k][c] >= 0){
                            t += grid[k][c];
                            money[k][c] = max(money[k][c], t);
                        }else{
                            break;
                        }
                    }
                }
            }
        }

        cout << money[rows-1][cols-1] << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;


// Strat: iterate through levels in increasing order, move player whose total cost will be less
// Pitfalls:
// can't move player from level x to level x+2 or something
// moves player with lowest total score, even if not lower cost to move that player

int wrongSolve(int N, vector<vector<int>> A){
    int x = 1, y = 1, sx = 0, sy = 0;
    for(int i=2;i<=N;i++){
        if(sx+A[x][i] < sy+A[y][i]){
            cout << "Player 1 to " << i << ", cost of " << A[x][i] << "\n";
            sx += A[x][i];
            x = i;
        }else{
            cout << "Player 2 to " << i << ", cost of " << A[y][i] << "\n";
            sy += A[y][i];
            y = i;
        }
    }
    return sx+sy;
}

int rightSolve(int N, vector<vector<int>> A){
    
}

void bestInput(){
    int N = 5; cout << N << "\n";
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-i-1;j++){
            cout << 0 << " ";
        }
        cout << "\n";
    }
}

int main(){
    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N+1));
    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;j++){
            cin >> A[i][j];
        }
    }

    cout << wrongSolve(N, A);
    bestInput();
}
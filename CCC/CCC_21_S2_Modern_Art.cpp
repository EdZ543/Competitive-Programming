#include <bits/stdc++.h>
using namespace std;

#define ll long long

int rows[5000001];
int cols[5000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M, N, K; cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        char direction; cin >> direction;
        int num; cin >> num;
        direction == 'R' ? rows[num]++ : cols[num]++;
    }
    int gold = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int layers = rows[i] + cols[j];
            if (layers % 2 != 0) gold++;
        }
    }
    cout << gold;
}
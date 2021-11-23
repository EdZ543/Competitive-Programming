#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int W, N; cin >> W >> N;
    vector<int> cars(N);
    for (int i = 0; i < N; i++) cin >> cars[i];
    int i = 0;
    while (i != N) {
        int weight = cars[i];
        for (int j = max(0, i-3); j < i; j++) weight += cars[j];
        if (weight > W) {
            break;
        }
        i++;
    }
    cout << i;
}
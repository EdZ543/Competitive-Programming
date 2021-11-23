#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int B; cin >> B;
    int P = 5 * B - 400;
    int seaLevel;
    if (P > 100) {
        seaLevel = -1;
    } else if (P == 100) {
        seaLevel = 0;
    } else {
        seaLevel = 1;
    }
    cout << P << "\n" << seaLevel;
}
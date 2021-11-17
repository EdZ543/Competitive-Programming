#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (true) {
        int r; cin >> r;
        if (r == 0) {
            break;
        }
        int outside = 0;
        for (int i = -r; i <= 0; i++) {
            for (int j = -r; j <= 0; j++) {
                if (i * i + j * j <= r * r) {
                    break;
                }
                outside++;
            }
        }
        outside *= 4;
        int totalArea = (r * 2 + 1) * (r * 2 + 1);
        cout << totalArea - outside << '\n';
    }
}
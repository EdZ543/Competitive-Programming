#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int p, g, r, o, x; cin >> p >> g >> r >> o >> x;
    int combinations = 0;
    int minTickets = INT_MAX;

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= x; k++) {
                for (int l = 0; l <= x; l++) {
                    if (i * p + j * g + k * r + l * o == x) {
                        combinations++;
                        cout << "# of PINK is " << i << ' ';
                        cout << "# of GREEN is " << j << ' ';
                        cout << "# of RED is " << k << ' ';
                        cout << "# of ORANGE is " << l << '\n';
                        minTickets = min(minTickets, i + j + k + l);
                    }
                }
            }
        }
    }

    cout << "Total combinations is " << combinations << ".\n";
    cout << "Minimum number of tickets to print is " << minTickets << ".";
}
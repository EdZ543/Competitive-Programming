#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q, a, b, c; cin >> q >> a >> b >> c;
    int times = 0;
    int machine = 1;
    while (q > 0) {
        if (machine == 1) {
            a += 1;
            if (a % 35 == 0) {
                q += 30;
            }             
        } else if (machine == 2) {
            b++;
            if (b % 100 == 0) {
                q += 60;
            } 
        } else {
            c++;
            if (c % 10 == 0) {
                q += 9;
            }
        }
        q--;
        times++;
        machine = (machine + 1) % 3;
    }
    cout << "Martha plays " << times << " times before going broke.";
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int c, r; cin >> c >> r;
    int xpos = 0, ypos = 0;
    while(true) {
        int x, y; cin >> x >> y;
        if (x == 0 && y == 0) {
            break;
        }
        xpos += x;
        ypos += y;
        if (xpos < 0) xpos = 0;
        if (xpos > c) xpos = c;
        if (ypos < 0) ypos = 0;
        if (ypos > r) ypos = r;
        cout << xpos << ' ' << ypos << '\n';
    }
}
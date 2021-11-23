#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(int m, int x, int y) {
    int len_of_area = (int)pow(5, m-1);
    int x1 = x % (int)len_of_area, y1 = y % (int)len_of_area;
    x = (x/len_of_area);
    y = (y/len_of_area);
    if ((x == 1 && y == 0) || (x == 2 && y == 0) || (x == 3 && y == 0) || (x == 2 && y == 1)) return true;
    if (m > 1 && ((x == 1 && y == 1) || (x == 2 && y == 2) || (x == 3 && y == 1))) return check(m-1, x1, y1);
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int m, x, y; cin >> m >> x >> y;
        check(m, x, y) ? cout << "crystal\n" : cout << "empty\n";
    }
}
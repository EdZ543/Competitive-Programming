#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int a, b, c, d, t;
    cin >> a >> b >> c >> d >> t;
    int xDistance = abs(c - a);
    int yDistance = abs(d - b);
    int totalDistance = xDistance + yDistance;
    bool possible = (t - totalDistance) % 2 == 0;
    if (possible && t >= totalDistance) {
        cout << "Y";
    } else {
        cout << "N";
    }
} 
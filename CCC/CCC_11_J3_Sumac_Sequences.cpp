#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int t1, t2, t3;
    cin >> t1 >> t2;
    int length = 2;
    while (true) {
        if (t1 < t2) {
            break;
        }
        t3 = t1 - t2;
        t1 = t2;
        t2 = t3;
        ++length;
    }
    cout << length;
} 
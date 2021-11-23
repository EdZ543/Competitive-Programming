#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int position = 1;
    
    while (true) {
        int x; cin >> x;
        if (x == 0) {
            cout << "You Quit!";
            break;
        }
        position += x;
        switch(position) {
            case 54:
                position = 19;
                break;
            case 90:
                position = 48;
                break;
            case 99:
                position = 77;
                break;
            case 9:
                position = 34;
                break;
            case 40:
                position = 64;
                break;
            case 67:
                position = 86;
                break;
        }
        if (position > 100) {
            position -= x;
        }
        cout << "You are now on square " << position << '\n';
        if (position == 100) {
            cout << "You Win!";
            break;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        string num; cin >> num;
        string res = "";
        int x = 0; 
        while (res.size() < 12) {
            char c = num[x];
            switch(c) {
                case '-':
                    x++;
                    continue; 
                case 'A':
                case 'B':
                case 'C':
                    c = '2';
                    break;
                case 'D':
                case 'E':
                case 'F':
                    c = '3';
                    break;
                case 'G':
                case 'H':
                case 'I':
                    c = '4';
                    break;
                case 'J':
                case 'K':
                case 'L':
                    c = '5';
                    break;
                case 'M':
                case 'N':
                case 'O':
                    c = '6';
                    break;
                case 'P':
                case 'Q':
                case 'R':
                case 'S':
                    c = '7';
                    break;
                case 'T':
                case 'U':
                case 'V':
                    c = '8';
                    break;
                case 'W':
                case 'X':
                case 'Y':
                case 'Z':
                    c = '9';
                    break;
            }
            res += c;
            if (res.size() == 3 || res.size() == 7) {
                res += "-";
            }
            x++;
        }
        cout << res << '\n';
    }
}
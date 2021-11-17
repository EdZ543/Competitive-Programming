#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string prev;
    while (true) {
        string s; cin >> s;
        if (s == "99999") break;
        int a = s[0] - '0';
        int b = s[1] - '0';
        int c = stoi(s.substr(2, 3));
        int sum = a + b;
        if (sum == 0) {
            cout << prev;
        } else if (sum % 2 == 0) {
            cout << "right ";
            prev = "right ";
        } else {
            cout << "left ";
            prev = "left ";
        }
        cout << c << "\n";
    }
}
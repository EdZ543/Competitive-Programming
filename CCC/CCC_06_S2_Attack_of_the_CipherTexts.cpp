#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string plain, cipher1, cipher2;
    getline(cin, plain);
    getline(cin, cipher1);
    getline(cin, cipher2);
    for (auto c : cipher2) {
        size_t found = cipher1.find(c);
        if (found != string::npos) {
            cout << plain[found];
        } else {
            cout << '.';
        }
    }
}
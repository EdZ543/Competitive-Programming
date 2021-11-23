#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    cin.ignore(); 
    int s = 0;
    int t = 0;
    for (int i = 0; i < N; i++) {
        string line; getline(cin, line);
        for (auto c : line) {
            if (tolower(c) == 't') {
                t++;
            } else if (tolower(c) == 's') {
                s++;
            }
        }
    }
    cout << (t > s ? "English" : "French");
}
#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string x;
        cin >> x;

        while (x.size() != 1) {
            int sum = 0;
            for (char c : x) {
                sum += c - '0';
            }
            x = to_string(sum);
        }

        cout << x << "\n";
    }
} 
#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int N;
    cin >> N;
    string yesterday, today;
    cin >> yesterday >> today;
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (yesterday[i] == 'C' && today[i] == 'C') {
            result++;
        }
    }
    cout << result;
} 
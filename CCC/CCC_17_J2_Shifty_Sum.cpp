#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int N, k;
    cin >> N >> k;
    int shiftySum = N;
    for (int i = 1; i <= k; i++) {
        shiftySum += N * pow(10, i);
    }
    cout << shiftySum;
} 
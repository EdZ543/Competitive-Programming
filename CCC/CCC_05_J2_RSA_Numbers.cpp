#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int min, max;
    cin >> min >> max;
    int RSANums = 0;

    for (int i = min; i <= max; i++) {
        int divisors = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                divisors++;
            }
        }
        if (divisors == 4) {
            RSANums++;
        }
    }

    cout << "The number of RSA numbers between " << min << " and " << max << " is " << RSANums;
} 
#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool perfect(int n) {
    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            if (i != 1) {
                sum += n / i;
            }
        }
    }
    return sum == n;
}

bool epic(int n) {
    string str = to_string(n);
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        int digit = str[i] - '0';
        sum += digit * digit * digit;
    }
    return sum == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 1000; i <= 9999; i++) {
        if (perfect(i)) cout << i << ' ';
    }
    cout << '\n';
    for (int i = 100; i <= 999; i++) {
        if (epic(i)) cout << i << ' ';
    }
}
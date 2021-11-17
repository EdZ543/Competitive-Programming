#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x; cin >> x;
    for (int i = 0; i < x; i++) {
        int num; cin >> num;
        int sum = 0;
        for (int j = 1; j < num; j++) {
            if (num % j == 0) {
                sum += j;
            }
        }
        cout << num;
        if (sum < num) {
            cout << " is a deficient number.\n";
        } else if (sum > num) {
            cout << " is an abundant number.\n";
        } else {
            cout << " is a perfect number.\n";
        }
    }
}
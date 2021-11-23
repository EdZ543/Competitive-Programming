#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string num; cin >> num;
    map<char, int> convert = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int value = 0;
    for (int i = 0; i < num.size(); i += 2) {
        int arabic = num[i] - '0';
        int base = convert[num[i+1]];
        int nextbase = convert[num[i+3]];
        int pairValue = arabic * base;
        if (i != num.size() - 2 && base < nextbase) {
            value -= pairValue;
        } else {
            value += pairValue;
        }
    }
    cout << value;
}
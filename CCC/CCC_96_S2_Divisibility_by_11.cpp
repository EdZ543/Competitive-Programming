#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool algorithm(vector<int> num) {
    for (auto digit : num) {
        cout << digit;
    }
    cout << '\n';
    if (num.size() <= 2) {
        string str = "";
        for (auto digit : num) {
            str += to_string(digit);
        }
        return stoi(str) % 11 == 0;
    }
    int unitsDigit = num.back();
    num.pop_back();
    num.back() -= unitsDigit;
    for (int i = num.size()-1; i > 0; i--) {
        if (num[i] < 0) {
            num[i-1]--;
            num[i] += 10;
        } else {
            break;
        }
    }
    if (num[0] == 0) {
        num.erase(num.begin());
    }
    return algorithm(num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        vector<int> num(str.size());
        for (int j = 0; j < str.size(); j++) {
            num[j] = str[j] - '0';
        }
        bool divisible = algorithm(num);
        cout << "The number " << str << ' ' << (divisible ? "is" : "is not") << " divisible by 11.\n";
        if (i != N-1) {
            cout << '\n';
        }
    }
}
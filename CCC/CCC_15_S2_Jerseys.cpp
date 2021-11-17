#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<char> jerseys(1000001);
vector<int> athletes(1000001, 4);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<char, int> convert = {
        {'S', 1},
        {'M', 2},
        {'L', 3}
    };

    int J, A; cin >> J >> A;
    for (int i = 1; i <= J; i++) cin >> jerseys[i];
    int requests = 0;
    for (int i = 0; i < A; i++) {
        char size; cin >> size;
        int num; cin >> num;
        athletes[num] = min(athletes[num], convert[size]);
    }
    for (int i = 1; i <= J; i++) {
        if (athletes[i] <= convert[jerseys[i]]) {
            requests++;
        }
    }
    cout << requests;
}
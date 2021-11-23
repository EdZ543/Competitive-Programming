#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    int swiftSum = 0;
    int semaSum = 0;
    vector<int> swift(N);
    vector<int> sema(N);
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        swiftSum += num;
        swift[i] = swiftSum;
    }
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        semaSum += num;
        sema[i] = semaSum;
    }
    int day = 0;
    for (int i = N-1; i >= 0; i--) {
        if (swift[i] == sema[i]) {
            day = i+1;
            break;
        }
    }
    cout << day;
}
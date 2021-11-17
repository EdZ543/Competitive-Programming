#include <bits/stdc++.h>
using namespace std;

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("div7");
    int N; cin >> N;
    int first[7];
    int last[7];
    fill(first, first + 7, numeric_limits<int>::max());
    fill(last, last + 7, 0);
    first[0] = 0;
    int prefixSum = 0;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        prefixSum += x;
        prefixSum %= 7;
        first[prefixSum] = min(i, first[prefixSum]);
        last[prefixSum] = i;
    }
    int longest = 0;
    for (int i = 0; i < 7; i++) {
        if (first[i] <= N) longest = max(longest, last[i] - first[i]);
    }
    cout << longest;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    int correct = 0;
    char responses[N];
    for (int i = 0; i < N; i++) cin >> responses[i];
    for (int i = 0; i < N; i++) {
        char answer; cin >> answer;
        if (answer == responses[i]) correct++;
    }
    cout << correct;
}
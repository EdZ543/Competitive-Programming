#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K; cin >> N >> K;
    int stacks[N+1];
    fill(stacks, stacks + N + 1, 0);
    for (int i = 0; i < K; i++) {
        int A, B; cin >> A >> B;
        A--;
        B--;
        stacks[A]++;
        stacks[B+1]--;
    }
    int real[N];
    int currentStack = 0;
    for (int i = 0; i < N; i++) {
        currentStack += stacks[i];
        real[i] = currentStack;
    }
    sort(real, real + N);
    cout << real[N/2];
}
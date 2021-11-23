#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N, K;
    cin >> N >> K;
    vector<int> as;
    vector<int> bs;
    int cows[N];
    vector<vector<int>> positions(N);
    int finished = 0;

    for (int i = 0; i < N; i++) {
        cows[i] = i;
        positions[i].push_back(i);
    }

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        as.push_back(a - 1);
        bs.push_back(b - 1);
    }

    int minutes = 0;
    while (true) {
        int temp = cows[as[minutes]];
        cows[as[minutes]] = cows[bs[minutes]];
        cows[bs[minutes]] = temp;

        minutes++;

        for (int i = 0; i < N; i++) {
            if (cows[i] != -1) {
                if (minutes >= K && cows[i] == i) {
                    cows[i] == -1;
                    finished++;
                } else if(find(positions[cows[i]].begin(), positions[cows[i]].end(), i) == 
                positions[cows[i]].end()) {
                    positions[cows[i]].push_back(i);
                }
            }
        }

        if (finished >= N) break;

        if (minutes >= K) minutes = 0;
    }

    for (vector<int> position : positions) {
        cout << position.size() << '\n';
    }
}
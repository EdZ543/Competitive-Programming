#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int N;
    cin >> N;

    vector<int> xs;
    vector<int> ys;
    for (int i = 0; i < N * 2; i++) {
        int coordinate;
        cin >> coordinate;
        if (i % 2 == 0) {
            xs.push_back(coordinate);
        } else {
            ys.push_back(coordinate);
        }
    }

    int shortestDiff = numeric_limits<int>::max();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (xs[i] != xs[j] || ys[i] != ys[j]) {
                int xDiff = abs(xs[i] - xs[j]);
                int yDiff = abs(ys[i] - ys[j]);
                int largestDiff = max(xDiff, yDiff);
                if (largestDiff < shortestDiff) {
                    shortestDiff = largestDiff;
                }
            }
        }
    }
    long long area = shortestDiff * shortestDiff;
    cout << area;
} 
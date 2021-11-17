#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> heights(N+1);
    for (int i = 0; i < N + 1; i++) cin >> heights[i];
    vector<int> widths(N);
    for (int i = 0; i < N; i++) cin >> widths[i];
    double area = 0;

    for (int i = 0; i < N; i++) {
        int height = max(heights[i], heights[i+1]);
        int width = widths[i];
        area += height * width;

        double removeHeight = abs(heights[i] - heights[i+1]);
        double removeArea = removeHeight * width;
        removeArea /= 2;
        area -= removeArea;
    }

    cout << setprecision(100) << area;
}
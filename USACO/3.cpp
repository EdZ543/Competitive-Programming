#include <bits/stdc++.h> 

using namespace std;

int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    long long N;
    cin >> N;
    vector<char> directions;
    vector<long long> xs;
    vector<long long> ys;
    vector<long long> grasses(N, 0);
    vector<bool> moving(N, true);

    for (long long i = 0; i < N; i++) {
        char direction;
        long long x, y;
        cin >> direction >> x >> y;
        directions.push_back(direction);
        xs.push_back(x);
        ys.push_back(y);
    }

    long long minX = *min_element(xs.begin(), xs.end());
    long long minY = *min_element(ys.begin(), ys.end());

    for (long long i = 0; i < xs.size(); i++) {
        xs[i] -= minX;
    }
    for (long long i = 0; i < ys.size(); i++) {
        ys[i] -= minY;
    }

    long long maxX = *max_element(xs.begin(), xs.end());
    long long maxY = *max_element(ys.begin(), ys.end());
    vector<long long> row(maxX + 5, 0);
    vector<vector<long long>> grid(maxY + 5, row);
    long long hours = 0;

    while (find(moving.begin(), moving.end(), true) != moving.end()) {
        hours++;

        for (long long i = 0; i < directions.size(); i++) {
            if ((grid[ys[i]][xs[i]] == 0 || grid[ys[i]][xs[i]] == hours) && moving[i] == true) {
                grid[ys[i]][xs[i]] = hours;

                if (directions[i] == 'N') {
                    ys[i]++;
                } else if (directions[i] == 'E'){
                    xs[i]++;
                }

                grasses[i]++;

                if (xs[i] > maxX + 3 || ys[i] > maxY + 3) {
                    grasses[i] = -1;
                    moving[i] = false;
                }

            } else {
                moving[i] = false;
            }
        }
    }

    for (long long grass : grasses) {
        if (grass == -1) {
            cout << "Infinity\n";
        } else {
            cout << grass << "\n";
        }
    }
} 
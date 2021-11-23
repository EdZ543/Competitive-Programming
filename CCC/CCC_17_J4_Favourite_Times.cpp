#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> patterns = {
    {12, 34},
    {1, 11},
    {1, 23},
    {1, 35},
    {1, 47},
    {1, 59},
    {2, 10},
    {2, 22},
    {2, 34},
    {2, 46},
    {2, 58},
    {3, 21},
    {3, 33},
    {3, 45},
    {3, 57},
    {4, 20},
    {4, 32},
    {4, 44},
    {4, 56},
    {5, 31},
    {5, 43},
    {5, 55},
    {6, 30},
    {6, 42},
    {6, 54},
    {7, 41},
    {7, 53},
    {8, 40},
    {8, 52},
    {9, 51},
    {11, 11}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int D;
    cin >> D;
    int h = 12;
    int m = 0;
    int numSq = 0;
    int fullCycles = (D - (D % 720)) / 720;
    int partialCycle = D % 720;
    
    numSq += 31 * fullCycles;

    for (int i = 0; i <= partialCycle; i++) {
        vector<int> time = {h, m};
        if (find(patterns.begin(), patterns.end(), time) != patterns.end()) {
            numSq++;
        }

        m++;
        if (m >= 60) {
            m -= 60;
            h++;
        }

        if (h >= 13) {
            h -= 12;
        }
    }

    cout << numSq;
}
#include <bits/stdc++.h>
using namespace std;

void addNextStartPositions(vector<pair<int, int>> &nextStartPositions, int x, int y) {
    if (x >= 1 && x <= 8 && y >= 1 && y <= 8) nextStartPositions.push_back({x, y});
}

int getMinJumps(vector<pair<int, int>> startPositions, pair<int, int> endPosition, int jumps) {
    if (find(startPositions.begin(), startPositions.end(), endPosition) != startPositions.end()) {
        return jumps;
    }

    jumps++;

    vector<pair<int, int>> nextStartPositions;

    for (int i = 0; i < startPositions.size(); i++) {
        int x = startPositions[i].first;
        int y = startPositions[i].second;

        addNextStartPositions(nextStartPositions, x+1, y+2);
        addNextStartPositions(nextStartPositions, x+2, y+1);
        addNextStartPositions(nextStartPositions, x+2, y-1);
        addNextStartPositions(nextStartPositions, x+1, y-2);
        addNextStartPositions(nextStartPositions, x-1, y-2);
        addNextStartPositions(nextStartPositions, x-2, y-1);
        addNextStartPositions(nextStartPositions, x-2, y+1);
        addNextStartPositions(nextStartPositions, x-1, y+2);
    }

    return getMinJumps(nextStartPositions, endPosition, jumps);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int startX, startY, endX, endY; cin >> startX >> startY >> endX >> endY;

    vector<pair<int, int>> startPositions{{startX, startY}};

    cout << getMinJumps(startPositions, {endX, endY}, 0);
}
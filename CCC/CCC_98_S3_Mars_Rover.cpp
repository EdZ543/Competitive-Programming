#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    while (n--) {
        int x = 0, y = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0;
        while (true) {
            int command; cin >> command;
            if (command == 0) {
                break;
            } else if (command == 1) {
                int distance; cin >> distance;
                x += directions[direction].first*distance;
                y += directions[direction].second*distance;
            } else if (command == 2) {
                direction++;
                if (direction == 4) direction = 0;
            } else if (command == 3) {
                direction--;
                if (direction == -1) direction = 3;
            }
        }
        cout << "Distance is " << abs(x)+abs(y) << "\n";

        vector<int> needDir;
        if (x > 0) {
            needDir.push_back(3);
        }
        if (x < 0) {
            needDir.push_back(1);
        }
        if (y > 0) {
            needDir.push_back(2);
        }
        if (y < 0) {
            needDir.push_back(0);
        }

        while (x != 0 || y != 0) {
            bool good = false;
            for (auto dir : needDir) {
                if (dir == direction) {
                    good = true;
                    if (dir == 0 || dir == 2) {
                        cout << 1 << "\n" << abs(y) << "\n";
                        y = 0;
                        needDir.erase(remove(needDir.begin(), needDir.end(), dir), needDir.end());
                        break;
                    } else if (dir == 1 || dir == 3) {
                        cout << 1 << "\n" << abs(x) << "\n";
                        x = 0;
                        needDir.erase(remove(needDir.begin(), needDir.end(), dir), needDir.end());
                        break;
                    }
                }
            }
            if (good) continue;

            bool good2 = false;
            int dirLeft = direction, dirRight = direction;
            dirLeft--;
            if (dirLeft == -1) dirLeft = 3;
            dirRight++;
            if (dirRight == 4) dirRight = 0;
            for (auto dir : needDir) {
                if (dir == dirRight) {
                    good2 = true;
                    cout << 2 << "\n";
                    direction = dirRight;
                    break;
                } else if (dir == dirLeft) {
                    good2 = true;
                    cout << 3 << "\n";
                    direction = dirLeft;
                    break;
                }
            }
            if (good2) continue;

            cout << 2 << "\n";
            direction = dirRight;
        }
        if (n != 0) cout << "\n";
    }
}
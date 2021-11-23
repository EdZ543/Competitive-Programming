#include <bits/stdc++.h>
using namespace std;
#define ll long long

int h, k;
vector<int> houses;

bool works(int house, int hosel) {
    int hy = houses[house]+hosel, hys = k-1;

    for (int i = house; i < h; i++) {
        if (abs(houses[i]-hy) > hosel) {
            if (hys > 0) {
                hys--;
                hy = houses[i]+hosel;
            } else {
                return false;
            }
        }
    }

    for (int i = 0; i < house; i++) {
        int housePos = houses[i] + 1000000;
        if (abs(housePos-hy) > hosel) {
            if (hys > 0) {
                hys--;
                hy = housePos+hosel;
            } else {
                return false;
            }
        }
    }

    return true;
}

bool good(int hosel) {
    for (int i = 0; i < h; i++) {
        if (works(i, hosel)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> h;
    for (int i = 0; i < h; i++) {
        int house; cin >> house;
        houses.push_back(house);
    }
    sort(houses.begin(), houses.end());
    cin >> k;

    int l = 0, r = 1000001;
    while (l < r) {
        int m = (l+r)/2;
        if (good(m)) {
            r = m;
        } else {
            l = m+1;
        }
    }
    cout << r << "\n";
}
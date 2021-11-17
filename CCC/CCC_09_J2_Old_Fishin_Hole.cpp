#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int bt, np, yp, limit;
    cin >> bt >> np >> yp >> limit;
    int numWays = 0;

    for (int bti = 0; bti <= limit/bt; bti++) {
        for (int npi = 0; npi <= limit/np; npi++) {
            for (int ypi = 0; ypi <= limit/yp; ypi++) {
                if (bti > 0 || npi > 0 || ypi > 0) {
                    if ((bti * bt) + (npi * np) + (ypi * yp) <= limit) {
                        numWays++;
                        cout << bti << " Brown Trout, " << npi << " Northern Pike, " << ypi << " Yellow Pickerel\n";
                    }
                }
            }
        }
    }

    cout << "Number of ways to catch fish: " << numWays;
}
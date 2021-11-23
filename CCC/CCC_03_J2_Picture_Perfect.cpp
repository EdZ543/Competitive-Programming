#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    while (true) {
        int numPhotos;
        cin >> numPhotos;
        int x = 65000;
        int y = 65000;

        if (numPhotos == 0) {
            break;
        }

        for (int i = 1; i < numPhotos; i++) {
            if (numPhotos % i == 0 && i + (numPhotos / i) < x + y) {
                x = i;
                y = numPhotos / i;
            }
        } 

        cout << "Minimum perimeter is " << 2 * (x + y) << " with dimensions " << x << " x " << y << "\n";
    }
} 
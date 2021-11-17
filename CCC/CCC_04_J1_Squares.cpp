#include <bits/stdc++.h>

using namespace std;

int main() {
    int tiles;
    cin >> tiles;

    int side_length = 0;

    while (pow(side_length + 1, 2) <= tiles) {
        side_length++;
    }

    cout << "The largest square has side length " << side_length << ".";
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int Array[3];
    std::for_each(std::begin(Array), std::end(Array), [](auto& elem) { cin >> elem; });
    sort(Array, Array + 3);
    cout << Array[1];
}
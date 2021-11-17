#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    vector<int> hints;

    for (int i = 0; i < 7; i++) {
        int hint;
        cin >> hint;
        hints.push_back(hint);
    }

    int ABC = *max_element(hints.begin(), hints.end());
    int A = *min_element(hints.begin(), hints.end());
    hints.erase(find(hints.begin(), hints.end(), A));
    int B = *min_element(hints.begin(), hints.end());
    int C = ABC - A - B;

    cout << A << " " << B << " " << C;
} 
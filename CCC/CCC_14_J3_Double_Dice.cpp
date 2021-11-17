#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int Apoints = 100;
    int Dpoints = 100;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int Aroll, Droll;
        cin >> Aroll >> Droll;
        if (Aroll > Droll) {
            Dpoints -= Aroll;
        } else if (Droll > Aroll) {
            Apoints -= Droll;
        }
    }  
    cout << Apoints << "\n" << Dpoints;
} 
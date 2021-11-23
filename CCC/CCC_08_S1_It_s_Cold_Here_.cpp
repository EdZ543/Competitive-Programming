#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string coldestCity = "";
    int coldestTemp = 201;
    while (true) {
        string city; cin >> city;
        int temp; cin >> temp;
        if (temp < coldestTemp) {
            coldestCity = city;
            coldestTemp = temp;
        }
        if (city == "Waterloo") {
            break;
        }
    }
    cout << coldestCity;
}
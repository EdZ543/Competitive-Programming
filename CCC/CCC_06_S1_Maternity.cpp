#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string mother, father; cin >> mother >> father;
    int X; cin >> X;
    for (int i = 0; i < X; i++) {
        string mothercopy = mother;
        string fathercopy = father;
        string baby; cin >> baby;
        string extra = "";
        baby += extra;
        bool valid = true;
        for (auto c : baby) {
            if (islower(c)) {
                if (mothercopy.find(c) != string::npos && fathercopy.find(c) != string::npos) {
                    mothercopy.erase(find(begin(mothercopy), end(mothercopy), c));
                    fathercopy.erase(find(begin(fathercopy), end(fathercopy), c));
                } else {
                    valid = false;
                }
            } else {
                if (mothercopy.find(c) != string::npos) {
                    mothercopy.erase(find(begin(mothercopy), end(mothercopy), c));
                } else if (fathercopy.find(c) != string::npos) {
                    fathercopy.erase(find(begin(fathercopy), end(fathercopy), c));
                } else {
                    valid = false;
                }
            }
        }
        cout << (valid ? "Possible baby.\n" : "Not their baby!\n");
    }
}
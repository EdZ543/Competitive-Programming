#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    string timeO;
    cin >> timeO;
    cout << timeO << " in Ottawa\n";
    timeO = string(4 - timeO.length(), '0') + timeO;
    int h = stoi(timeO.substr(0, 2));
    int m = stoi(timeO.substr(2, 2));
    
    for (int i = 0; i < 180; i++) {
        m--;

        if (m < 0) {
            m = 59;
            h--;
        }
        if (h < 0) {
            h = 23;
        }
    }

    int mUp = 0;
    while (true) {
        if (mUp == 0) {
            if (h == 0) {
                cout << m << " in Victoria\n";
            } else {
                cout << to_string(h) + string(2 - to_string(m).length(), '0') + to_string(m) << " in Victoria\n";
            }
        } else if (mUp == 60) {
            if (h == 0) {
                cout << m << " in Edmonton\n";
            } else {
                cout << to_string(h) + string(2 - to_string(m).length(), '0') + to_string(m) << " in Edmonton\n";
            }
        } else if (mUp == 120) {
            if (h == 0) {
                cout << m << " in Winnipeg\n";
            } else {
                cout << to_string(h) + string(2 - to_string(m).length(), '0') + to_string(m) << " in Winnipeg\n";
            }
        } else if (mUp == 180) {
            if (h == 0) {
                cout << m << " in Toronto\n";
            } else {
                cout << to_string(h) + string(2 - to_string(m).length(), '0') + to_string(m) << " in Toronto\n";
            }
        } else if (mUp == 240) {
            if (h == 0) {
                cout << m << " in Halifax\n";
            } else {
                cout << to_string(h) + string(2 - to_string(m).length(), '0') + to_string(m) << " in Halifax\n";
            }
        } else if (mUp == 270) {
            if (h == 0) {
                cout << m << " in St. John's\n";
            } else {
                cout << to_string(h) + string(2 - to_string(m).length(), '0') + to_string(m) << " in St. John's\n";
            }
            break;
        }
        
        mUp++;
        m++;
        if (m > 59) {
            m = 0;
            h++;
        }
        if (h > 23) {
            h = 0;
        }
    }
} 

// V -180 0
// E -120 60
// W -60 120
// O +0 180
// T +0 180
// H +60 240
// S +90 270
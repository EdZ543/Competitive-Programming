#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    vector<long long> cases = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000,  1000000};
    vector<long long> caseNums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    long long n;
    cin >> n;
    
    for (long long i = 0; i < n; i++) {
        long long openedCase;
        cin >> openedCase;
        int index;
        vector<long long>::iterator it = find(caseNums.begin(), caseNums.end(), openedCase);
        if(it != caseNums.end()) {
            index = distance(caseNums.begin(), it);
        }
        cases.erase(cases.begin() + index);
        caseNums.erase(caseNums.begin() + index);
    }

    long long average = 0;
    for (long long kase : cases) {
        average += kase;
    }
    average /= cases.size();

    long long offer;
    cin >> offer;
    if (offer > average) {
        cout << "deal";
    } else {
        cout << "no deal";
    }
} 
#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int a, b, c, d, s;
    cin >> a >> b >> c >> d >> s;
    vector<vector<int>> people;
    people.push_back({a, b});
    people.push_back({c, d});

    vector<int> distances;
    for (vector<int> person : people) {
        int F = person[0];
        int B = person[1];
        int D = 0;
        int unfinishedC = s % (F + B);
        int numC = (s - unfinishedC) / (F + B);
        D += numC * (F - B);
        if (unfinishedC > F) {
            D += F - (unfinishedC - F);
        } else {
            D += unfinishedC;
        }
        distances.push_back(D);
    }

    if (distances[0] > distances[1]) {
        cout << "Nikky";
    } else if(distances[1] > distances[0]) {
        cout << "Byron";
    } else {
        cout << "Tied";
    }
    
} 
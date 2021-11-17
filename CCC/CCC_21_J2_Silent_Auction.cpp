#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<pair<string, int>> people(N);
    for (int i = 0; i < N; i++) {
        cin >> people[i].first >> people[i].second;
    }
    string highestPerson;
    int highest = 0;
    for (auto person : people) {
        if (person.second > highest) {
            highestPerson = person.first;
            highest = person.second;
        }
    }
    cout << highestPerson;
}
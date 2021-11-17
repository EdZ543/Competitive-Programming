#include <bits/stdc++.h>
using namespace std;

vector<string> names;
vector<string> phoneNumbers;
vector<int> frequencies;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string name, phoneNumber;
        cin >> name >> phoneNumber;
        names.push_back(name);
        phoneNumbers.push_back(phoneNumber);
        frequencies.push_back(0);
    }
    int D;
    cin >> D;
    for (int i = 0; i < D; i++) {
        string phoneNumber;
        cin >> phoneNumber;
        vector<string>::iterator it = find(phoneNumbers.begin(), phoneNumbers.end(), phoneNumber);
        if(it != phoneNumbers.end()) {
            int index = distance(phoneNumbers.begin(), it);
            frequencies[index]++;
        }
    }
    int maxIndex = 0;
    for (int i = 0; i < names.size(); i++) {
        if (frequencies[i] > frequencies[maxIndex]) {
            maxIndex = i;
        } else if (frequencies[i] == frequencies[maxIndex] && stoi(phoneNumbers[i]) < stoi(phoneNumbers[maxIndex])) {
            maxIndex = i;
        }
    }

    cout << names[maxIndex];
}
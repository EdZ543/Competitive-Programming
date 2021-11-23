#include <bits/stdc++.h>
using namespace std;

bool sortCol(vector<int> v1, vector<int> v2) {
    return v1[0] < v2[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int L, N;
    cin >> L >> N;
    vector<vector<int>> animals;
    int longest = 0;

    for (int i = 0; i < N; i++) {
        int s, t;
        cin >> s >> t;
        animals.push_back({s, t});
    }

    sort(animals.begin(), animals.end(), sortCol);

    int leftAnimal = 0;
    for (vector<int> animal : animals) {
        longest = max(animal[0] - leftAnimal, longest);
        leftAnimal = max(animal[1], leftAnimal);
    }
    longest = max(L - leftAnimal, longest);
    cout << longest;
}
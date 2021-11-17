#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int N;
    cin >> N;
    vector<int> flowers;
    int numAverages = 0;

    for (int i = 0; i < N; i++) {
        int flower;
        cin >> flower;
        flowers.push_back(flower);
    }

    for (int i = 0; i < flowers.size(); i++) {
        for (int j = i; j < flowers.size(); j++) {
            vector<int> flowerInterval;
            double sum = 0;
            for (int x = i; x <= j; x++) {
                flowerInterval.push_back(flowers[x]);
                sum += flowers[x];
            }
            sum /= flowerInterval.size();
            if(find(flowerInterval.begin(), flowerInterval.end(), sum) != flowerInterval.end()) {
                numAverages++;
            }
        }
    }

    cout << numAverages;
} 
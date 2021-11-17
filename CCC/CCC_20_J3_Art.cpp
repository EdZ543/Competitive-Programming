#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int N;
    cin >> N;
    vector<int> xs;
    vector<int> ys;

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        vector<int> tokens; 
        stringstream check1(line); 
        string intermediate; 
        while(getline(check1, intermediate, ',')) { 
            tokens.push_back(stoi(intermediate)); 
        }
        xs.push_back(tokens[0]);
        ys.push_back(tokens[1]);
    }

    int x1, y1, x2, y2;
    x1 = *min_element(xs.begin(), xs.end()) - 1;
    y1 = *min_element(ys.begin(), ys.end()) - 1;
    x2 = *max_element(xs.begin(), xs.end()) + 1;
    y2 = *max_element(ys.begin(), ys.end()) + 1;

    cout << x1 << ',' << y1 << "\n";
    cout << x2 << ',' << y2;
}

#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    int V;
    cin >> V;
    string votes;
    cin >> votes;

    int AVotes = 0;
    int BVotes = 0;

    for (char vote : votes) {
        if (vote == 'A') {
            AVotes++;
        } else {
            BVotes++;
        }
    }

    if (AVotes > BVotes) {
        cout << "A";
    } else if (BVotes > AVotes) {
        cout << "B";
    } else {
        cout << "Tie";
    }
} 
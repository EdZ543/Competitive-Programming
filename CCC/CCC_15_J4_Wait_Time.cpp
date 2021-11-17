#include <bits/stdc++.h>
using namespace std;

vector<int> friends;
vector<int> waitTimes;
vector<bool> replied;


int getIndex(int num) {
    vector<int>::iterator it = find(friends.begin(), friends.end(), num);
    return distance(friends.begin(), it);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        char letter;
        int num;
        cin >> letter >> num;

        if (letter == 'R') {
            if (find(friends.begin(), friends.end(), num) == friends.end()) {
                friends.push_back(num);
                waitTimes.push_back(0);
                replied.push_back(false);
            } else {
                replied[getIndex(num)] = false;
            }

            for (int i = 0; i < friends.size(); i++) {
                if (friends[i] != num && replied[i] == false) {
                    waitTimes[i]++;
                }
            }
        } else if (letter == 'S') {
            for (int i = 0; i < friends.size(); i++) {
                if (replied[i] == false) {
                    waitTimes[i]++;
                }
            }

            replied[getIndex(num)] = true;
        } else if (letter == 'W') {
            for (int i = 0; i < friends.size(); i++) {
                if (replied[i] == false) {
                    waitTimes[i] += num - 1;
                }
            }
        }
    }

    while (friends.size() > 0) {
        int min = *min_element(friends.begin(), friends.end());
        vector<int>::iterator it = find(friends.begin(), friends.end(), min);
        int index = distance(friends.begin(), it);

        cout << friends[index] << " ";

        if (replied[index] == false) {
            cout << -1 << "\n";
        } else {
            cout << waitTimes[index] << "\n";
        }

        friends.erase(friends.begin() + index);
        waitTimes.erase(waitTimes.begin() + index);
        replied.erase(replied.begin() + index);
    }
}
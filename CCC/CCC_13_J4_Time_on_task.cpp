#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int T, C;
    cin >> T >> C;
    vector<int> chores;
    int numChores = 0;

    for (int i = 0; i < C; i++) {
        int a;
        cin >> a;
        chores.push_back(a);
    }

    while (true) {
        int min = *min_element(chores.begin(), chores.end());
        vector<int>::iterator it = find(chores.begin(), chores.end(), min);
        if (it != chores.end()) {
            int index = distance(chores.begin(), it);
            chores.erase(chores.begin() + index);
        }
        T -= min;
        if (T < 0) {
            break;
        } else {
            numChores++;
        }
    }

    cout << numChores;
}
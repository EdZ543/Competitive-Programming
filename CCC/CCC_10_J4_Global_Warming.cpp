#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	while (true) {
        int n;
        cin >> n;
        vector<int> sequence;
        vector<int> differences;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sequence.push_back(a);
        }

        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }

        for (int i = 0; i < sequence.size(); i++) {
            if (i > 0) {
                differences.push_back(sequence[i] - sequence[i - 1]);
            }
        }

        for (int size = 1; size <= differences.size(); size++) {
            bool works = true;
            for (int i = 0; i < size; i++) {
                for (int j = i; j < differences.size(); j += size) {
                    if (differences[j] != differences[i]) {
                        works = false;
                    }
                }
            }

            if (works) {
                cout << size << "\n";
                break;
            }
        }
    }
}
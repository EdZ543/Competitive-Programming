#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N; cin >> N;
    vector<int> invitations[N + 1];
    vector<vector<int>> list; 

    for (int i = 1; i < N; i++) {
        int invitor; cin >> invitor;
        invitations[invitor].push_back(i);
    }

    for (int i = 0; i < (int) pow(2, N); i++) { 
        vector<int> subset; 
   
        for (int j = 1; j <= N; j++) { 
            if ((i & (1 << j)) != 0) {
                subset.push_back(j); 
            }
        } 
  
        if (find(list.begin(), list.end(), subset) == list.end()) {
            bool valid = true;

            for (int person : subset) {
                if (person == N) {
                    valid = false;
                    break;
                }

                for (int invitation : invitations[person]) {
                    if (find(subset.begin(), subset.end(), invitation) == subset.end()) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid) list.push_back(subset); 
        }
    } 

    cout << list.size();
}
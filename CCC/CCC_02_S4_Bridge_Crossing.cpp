#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, q; cin >> m >> q;
    vector<int> queue(q);
    vector<string> names(q);
    vector<int> min_times(q);
    vector<vector<vector<string>>> min_names(q);
    for(int i=0;i<q;i++) cin >> names[i] >> queue[i];

    for(int i=0;i<q;i++){
        int min_time = INT_MAX;
        int slowest = 0;
        vector<string> group_names;
        vector<string> min_group_names;
        int best_past_names = -1;
        for(int j=i;j>=max(i-m+1, 0);j--){
            slowest = max(slowest, queue[j]);
            int past_min = (j == 0) ? 0 : min_times[j-1];
            group_names.insert(group_names.begin(), names[j]);
            if (slowest+past_min < min_time) {
                min_time = slowest+past_min;
                min_group_names = group_names;
                if (j == 0) {
                    best_past_names = -1;
                } else {
                    best_past_names = j-1;
                }
            }
        }
        min_times[i] = min_time;
        if (best_past_names != -1) {
            for (vector<string> group : min_names[best_past_names]) {
                min_names[i].push_back(group);
            }
        }
        min_names[i].push_back(min_group_names);
    }

    cout << "Total Time: " << min_times[q-1] << "\n";
    for (auto group : min_names[q-1]) {
        for (auto name : group) {
            cout << name << " ";
        }
        cout << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<vector<int>> rules = {
        {1, 7},
        {1, 4},
        {2, 1},
        {3, 4},
        {3, 5}
    };
    vector<int> tasks = {1, 2, 3, 4, 5, 6, 7};
    string output;

    while (true) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            break;
        }
        rules.push_back({x, y});
    }
    
    while (true) {
        if (tasks.size() == 0) {
            cout << output;
            break;
        }

        vector<int> noPrerequisites = tasks;
        vector<int> noPrerequisitesToRemove;

        for (vector<int> rule : rules) {
            noPrerequisitesToRemove.push_back(rule[1]);
        }

        for (int noPrerequisiteToRemove : noPrerequisitesToRemove) {
            noPrerequisites.erase(remove(noPrerequisites.begin(), noPrerequisites.end(), noPrerequisiteToRemove), noPrerequisites.end());
        }

        if (noPrerequisites.size() == 0 && tasks.size() != 0) {
            cout << "Cannot complete these tasks. Going to bed.";
            break;
        }

        int minNoPrerequisite = *min_element(noPrerequisites.begin(), noPrerequisites.end());
        tasks.erase(remove(tasks.begin(), tasks.end(), minNoPrerequisite), tasks.end());
        output += to_string(minNoPrerequisite) + " ";

        vector<vector<int>> rulesToRemove;

        for (size_t i = 0; i < rules.size(); i++) {
            if (rules[i][0] == minNoPrerequisite) {
                rulesToRemove.push_back(rules[i]);
            }
        }

        for (vector<int> ruleToRemove : rulesToRemove) {
            rules.erase(remove(rules.begin(), rules.end(), ruleToRemove), rules.end());
        }
    }
}
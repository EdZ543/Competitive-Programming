#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K; cin >> K;
    vector<int> nums;
    for (int i = 0; i < K; i++) {
        int num; cin >> num;
        if (num == 0) {
            nums.pop_back();
        } else {
            nums.push_back(num);
        }
    }
    int sum = 0;
    for (auto num : nums) {
        sum += num;
    }
    cout << sum;
}
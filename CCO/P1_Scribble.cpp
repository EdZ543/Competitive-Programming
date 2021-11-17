#include <bits/stdc++.h>
using namespace std;

int k, n;
map<char, pair<int, int>> m;

int main(){
    cin >> k;
    for(int i=0;i<k;i++){
        char letter; int score, times; cin >> letter >> score >> times;
        m[letter] = {score, times};
    }
    cin >> n;
    int sol = 0;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        auto copy = m;
        int score = 0;
        for(int j=0;j<s.size();j++){
            if(copy[s[j]].second > 0){
                score += copy[s[j]].first;
                copy[s[j]].second--;
            }else{
                score = 0;
                break;
            }
        }
        sol = max(sol, score);
    }
    cout << sol;
}
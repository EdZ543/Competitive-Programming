#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int s, v, o; cin >> s >> v >> o;
        cin.ignore();
        vector<string> subjects(s);
        for (int j = 0; j < s; j++) getline(cin, subjects[j]);
        vector<string> verbs(v);
        for (int j = 0; j < v; j++) getline(cin, verbs[j]);
        vector<string> objects(o);
        for (int j = 0; j < o; j++) getline(cin, objects[j]);
        for (int subject = 0; subject < s; subject++) {
            for (int verb = 0; verb < v; verb++) {
                for (int object = 0; object < o; object++) {
                    cout << subjects[subject] << ' ' << verbs[verb] << ' ' << objects[object] << ".\n";
                }
            }
        }
    }
}
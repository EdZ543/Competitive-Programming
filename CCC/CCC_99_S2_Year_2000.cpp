#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> getMatches(string str, regex rx) {
    vector<int> index_matches;

    for(auto it = std::sregex_iterator(str.begin(), str.end(), rx);
        it != std::sregex_iterator();
        ++it)
    {
        index_matches.push_back(it->position());
    }
    return index_matches;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    cin.ignore();
    for (int n = 0; n < N; n++) {
        string line; getline(cin, line);

        regex re("[ ]");
		sregex_token_iterator first{line.begin(), line.end(), re, -1}, last;
		vector<string> words{first, last};

        map<string, int> strToDays = {
            {"January", 31}, 
            {"February", 28},
            {"March", 31}, 
            {"April", 30}, 
            {"May", 31}, 
            {"June", 31}, 
            {"July", 31}, 
            {"August", 31}, 
            {"September", 30}, 
            {"October", 31}, 
            {"November", 30}, 
            {"December", 31},
        };
        map<int, int> intToDays = {
            {1, 31}, 
            {2, 28},
            {3, 31}, 
            {4, 30}, 
            {5, 31}, 
            {6, 31}, 
            {7, 31}, 
            {8, 31}, 
            {9, 30}, 
            {20, 31}, 
            {11, 30}, 
            {12, 31},
        };
        regex rx1("\\d\\d/\\d\\d/\\d\\d,?");
        regex rx2("\\d\\d\\.\\d\\d\\.\\d\\d,?");
        regex rx3("\\d\\d,?");
        for (int i = 0; i < words.size(); i++) {
            if (regex_match(words[i], rx1)) {
                int day = stoi(words[i].substr(0, 2));
                int month = stoi(words[i].substr(3, 2));
                int year = stoi(words[i].substr(6, 2));
                if (intToDays.find(month) != intToDays.end() && day <= intToDays[month]) {
                    words[i].insert(6, year <= 24 ? "20" : "19");
                }
            } else if (regex_match(words[i], rx2)) {
                int year = stoi(words[i].substr(0, 2));
                int month = stoi(words[i].substr(3, 2));
                int day = stoi(words[i].substr(6, 2));
                if (intToDays.find(month) != intToDays.end() && day <= intToDays[month]) {
                    words[i].insert(0, year <= 24 ? "20" : "19");
                }
            } else if (i < words.size() - 2 && strToDays.find(words[i]) != strToDays.end() && regex_match(words[i+1], rx3) && regex_match(words[i+2], rx3)) {
                string month = words[i];
                int day = stoi(words[i+1].substr(0, 2));
                int year = stoi(words[i+2].substr(0, 2));
                if (day <= strToDays[month]) {
                    words[i+2].insert(0, year <= 24 ? "20" : "19");
                }
            }
        }

        for (int i = 0; i < words.size(); i++) {
            cout << words[i];
            if (i != words.size()-1) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string line; getline(cin, line);
        // regex reg1("(^|\n)\\w\\w\\w\\w\\s");
        // line = regex_replace(line, reg1, "**** ");
        // regex reg2("\\s\\w\\w\\w\\w\\s");
        // line = regex_replace(line, reg2, " **** ");
        // regex reg3("\\s\\w\\w\\w\\w($|\n)");
        // line = regex_replace(line, reg3, " ****");
        // regex reg4("(^|\n)\\w\\w\\w\\w($|\n)");
        // line = regex_replace(line, reg4, "****");
        // cout << line << '\n';
        vector<string> tokens; 
        stringstream check1(line); 
        string intermediate; 
        while(getline(check1, intermediate, ' ')) { 
            tokens.push_back(intermediate); 
        }
        for (auto& word : tokens) {
            if (word.size() == 4) {
                word = "****";
            }
        }
        string res = tokens[0];
        for (int i = 1; i < tokens.size(); i++) {
            res += " " + tokens[i];
        }
        cout << res << '\n';
    }
}
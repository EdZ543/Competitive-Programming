#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    while (true) {
        string shortForm;
        cin >> shortForm;

        if (shortForm == "TTYL") {
            cout << "talk to you later";
            break;
        }

        vector<string> shortForms = {"CU",
                                    ":-)",
                                    ":-(",
                                    ";-)",
                                    ":-P",
                                    "(~.~)",
                                    "TA",
                                    "CCC",
                                    "CUZ",
                                    "TY",
                                    "YW"};
        vector<string> translations = {"see you",
                                    "I'm happy",
                                    "I'm unhappy",
                                    "wink",
                                    "stick out my tongue",
                                    "sleepy",
                                    "totally awesome",
                                    "Canadian Computing Competition",
                                    "because",
                                    "thank-you",
                                    "you're welcome"};
        
        vector<string>::iterator it = find(shortForms.begin(), shortForms.end(), shortForm);
        if(it != shortForms.end()) {
            int index = distance(shortForms.begin(), it);
            cout << translations[index] << "\n";
        } else {
            cout << shortForm << "\n";
        }
    }
} 
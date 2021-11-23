#include <bits/stdc++.h> 

using namespace std; 

int calculate(string varOne, string varTwo, int A, int B, char operation) {
    int varOneValue, varTwoValue;

    if (varOne == "A") {
        varOneValue = A;
    } else {
        varOneValue = B;
    }

    if (varTwo == "A") {
        varTwoValue = A;
    } else {
        varTwoValue = B;
    }

    switch (operation) {
        case '+':
            return varOneValue + varTwoValue;
            break;
        case 'x':
            return varOneValue * varTwoValue;
            break;
        case '-':
            return varOneValue - varTwoValue;
            break;
        case '/':
            return varOneValue / varTwoValue;
            break;
    }

    return 0;
}

int main() { 
    int A = 0;
    int B = 0;

    vector<vector<string>> instructions;
    while (true) {
        string line;
        getline(cin, line);
        
        vector<string> tokens; 
        stringstream check1(line); 
        string intermediate; 
        while (getline(check1, intermediate, ' ')) { 
            tokens.push_back(intermediate); 
        }

        instructions.push_back(tokens);

        if (tokens[0] == "7") {
            break;
        }
    }

    for (vector<string> instruction : instructions) {
        switch (stoi(instruction[0])) {
            case 1:
                if (instruction[1] == "A") {
                    A = stoi(instruction[2]);
                } else {
                    B = stoi(instruction[2]);
                }
                break;
            case 2:
                if (instruction[1] == "A") {
                    cout << A << "\n";
                } else {
                    cout << B << "\n";
                }
                break;
            case 3:
                if (instruction[1] == "A") {
                    A = calculate(instruction[1], instruction[2], A, B, '+');
                } else {
                    B = calculate(instruction[1], instruction[2], A, B, '+');
                }
                break;
            case 4:
                if (instruction[1] == "A") {
                    A = calculate(instruction[1], instruction[2], A, B, 'x');
                } else {
                    B = calculate(instruction[1], instruction[2], A, B, 'x');
                }
                break;
            case 5:
                if (instruction[1] == "A") {
                    A = calculate(instruction[1], instruction[2], A, B, '-');
                } else {
                    B = calculate(instruction[1], instruction[2], A, B, '-');
                }
                break;
            case 6:
                if (instruction[1] == "A") {
                    A = calculate(instruction[1], instruction[2], A, B, '/');
                } else {
                    B = calculate(instruction[1], instruction[2], A, B, '/');
                }
                break;
            case 7:
                break;
        }
    }   
} 
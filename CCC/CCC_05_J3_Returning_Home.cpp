#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    vector<string> instructions = {" into your HOME."};

    while (true) {
        string instruction;
        cin >> instruction;
        if (instruction == "SCHOOL") {
            break;
        } else if (instruction == "R") {
            instruction = "LEFT";
        } else if (instruction == "L") {
            instruction = "RIGHT";
        } else {
            instruction = " onto " + instruction + " street.";
        }
        instructions.push_back(instruction);
    }

    for (int i = instructions.size() - 1; i >= 0; i -= 2) {
        cout << "Turn " << instructions[i] << instructions[i - 1] << "\n";
    }
} 
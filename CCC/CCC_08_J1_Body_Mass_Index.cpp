#include <bits/stdc++.h>

using namespace std;

int main() {
    float weight;
    float height;

    cin >> weight;
    cin >> height;

    int BMI = weight/(height*height);

    if (BMI > 25) {
        cout << "Overweight";
    } else if (BMI >= 18.5 && BMI <= 25.0) {
        cout << "Normal weight";
    } else if (BMI < 18.5) {
        cout << "Underweight";
    }
}
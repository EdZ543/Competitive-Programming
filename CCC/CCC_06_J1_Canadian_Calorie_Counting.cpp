#include <bits/stdc++.h>

using namespace std;

int main() {
    int burger;
    int side;
    int drink;
    int dessert;
    int total = 0;

    cin >> burger;
    cin >> side;
    cin >> drink;
    cin >> dessert;

    switch(burger) {
        case 1:
            total += 461;
            break;
        case 2:
            total += 431;
            break;
        case 3: 
            total += 420;
            break;
        case 4:
            break;
    }

    switch(side) {
        case 1:
            total += 100;
            break;
        case 2:
            total += 57;
            break;
        case 3: 
            total += 70;
            break;
        case 4:
            break;
    }

    switch(drink) {
        case 1:
            total += 130;
            break;
        case 2:
            total += 160;
            break;
        case 3: 
            total += 118;
            break;
        case 4:
            break;
    }

    switch(dessert) {
        case 1:
            total += 167;
            break;
        case 2:
            total += 266;
            break;
        case 3: 
            total += 75;
            break;
        case 4:
            break;
    }

    cout << "Your total Calorie count is " << total << ".";
}
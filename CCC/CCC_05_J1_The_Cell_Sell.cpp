#include <bits/stdc++.h>

using namespace std;

int main() {
    float plan_A_total = 0;
    float plan_B_total = 0;

    float daytime;
    float evening;
    float weekend;

    cin >> daytime;
    cin >> evening;
    cin >> weekend;

    if (daytime > 100) {
        plan_A_total += (daytime - 100) * 25;
    }
    if (daytime > 250) {
        plan_B_total += (daytime - 250) * 45;
    }

    plan_A_total += evening * 15;
    plan_B_total += evening * 35;

    plan_A_total += weekend * 20;
    plan_B_total += weekend * 25;

    cout << "Plan A costs " << plan_A_total / 100;
    cout << "\nPlan B costs " << plan_B_total / 100;

    if (plan_A_total > plan_B_total) {
        cout << "\nPlan B is cheapest.";
    } else if (plan_B_total > plan_A_total) {
        cout << "\nPlan A is cheapest.";
    } else {
        cout << "\nPlan A and B are the same price.";
    }
}
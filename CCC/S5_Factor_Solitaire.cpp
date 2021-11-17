#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    int cost = 0;
    while(n != 1){
        for(int i=n/2;i>=1;i--){
            int j = n-i;
            if(j % i == 0){
                n -= i;
                cost += j/i;
                break;
            }
        }
    }
    cout << cost;
}
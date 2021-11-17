#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        
        vector<int> adj(n+1);
        for(int i=0;i<n;i++){
            int a, b; cin >> a >> b;
            adj[a] = b;
        }

        int sol = 1;
        for(int i=0;i<n;i++){
            int steps = 1;
            int current = adj[i];
            while(current != i){
                current = adj[current];
                steps++;
            }
            sol = lcm(sol, steps);
        }

        cout << sol << "\n";
    }
}
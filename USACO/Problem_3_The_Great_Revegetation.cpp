#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int limit = 1e5+1;
int n, m, sol = 0;
vector<int> sadj[limit], dadj[limit], labels(limit);
bool good = true;

void dfs(int node, int label) {
    labels[node] = label;
    for (auto u : sadj[node]) {
        if (labels[u] == 0) {
            dfs(u, label);
        } else if (labels[u] != label) {
            good = false;
        }
    }
    for (auto u : dadj[node]) {
        if (labels[u] == 0) {
            dfs(u, 3-label);
        } else if (labels[u] == label) {
            good = false;
        }
    }
}

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("revegetate");
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        int a, b; cin >> a >> b;
        if (c == 'S') {
            sadj[a].push_back(b);
            sadj[b].push_back(a);
        } else {
            dadj[a].push_back(b);
            dadj[b].push_back(a);
        }
    } 

    for (int i = 1; i <= n; i++) {
        if (labels[i] == 0) {
            sol++;
            dfs(i, 1);
        }
    }

    if (!good) {
        cout << 0;
    } else {
        cout << 1;
        for (int i = 0; i < sol; i++) {
            cout << 0;
        }
    }
}
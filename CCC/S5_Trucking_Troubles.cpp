#include <bits/stdc++.h>
using namespace std;

int c, r, d;
vector<pair<int, int>> adj[10001];
vector<int> maxw(10001, 0);
vector<bool> vis(10001, false);

void kruskal(){
    priority_queue<pair<int, int>> pq;
    pq.push({INT_MAX, 1});
    for(int i=0;i<c;i++){
        int cur = pq.top().second;
        maxw[cur] = pq.top().first;
        vis[cur] = true;
        pq.pop();
        for(auto u:adj[cur]) pq.push(u);
        while(vis[pq.top().second] && !pq.empty()) pq.pop();
    }
}

int main() {
    cin >> c >> r >> d;
    for(int i=0;i<r;i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
    }

    kruskal();
    
    int sol = INT_MAX;
    for(int i=0;i<d;i++){
        int dest; cin >> dest;
        sol = min(sol, maxw[dest]);
    }
    cout << sol << "\n";
}
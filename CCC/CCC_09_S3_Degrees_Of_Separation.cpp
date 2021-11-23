#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> adj[50];

int bfs(int startNode, int targetNode) {
    queue<int> bfsQueue;
    vector<bool> visited(50);
    vector<int> parent(50);

    visited[startNode] = true;
    bfsQueue.push(startNode);
    bool good = false;

    while (!bfsQueue.empty()) {
        int currentNode = bfsQueue.front();
        if (currentNode == targetNode) {
            good = true;
            break;
        }
        bfsQueue.pop();

        for (auto neighbour: adj[currentNode]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                bfsQueue.push(neighbour);
                parent[neighbour] = currentNode;
            }
        }
                
    }

    if (!good) {
        return 0;
    } else {
        int backtrack = targetNode;
        int dist = 0;
        while (backtrack != startNode) {
            backtrack = parent[backtrack];
            dist++;
        }
        return dist;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> init = {
        {2, 6},
        {1, 6},
        {3, 6},
        {6, 7},
        {6, 4},
        {6, 5},
        {4, 5},
        {3, 4},
        {3, 5},
        {12, 9},
        {18, 16},
        {16, 17},
        {17, 18},
        {12, 13},
        {3, 15},
        {15, 13},
        {13, 14},
        {7, 8},
        {8, 9},
        {9, 10},
        {10, 11},
        {11, 12}
    };

    for (auto con : init) {
        adj[con.first].push_back(con.second);
        adj[con.second].push_back(con.first);
    }
    
    while (true) {
        char c; cin >> c;
        if (c == 'i') {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        } else if (c == 'd') {
            int x, y; cin >> x >> y;
            adj[x].erase(remove(adj[x].begin(), adj[x].end(), y), adj[x].end());
            adj[y].erase(remove(adj[y].begin(), adj[y].end(), x), adj[y].end());
        } else if (c == 'n') {
            int x; cin >> x;
            cout << adj[x].size() << "\n";
        } else if (c == 'f') {
            int x; cin >> x;
            set<int> palofpals;
            int test = 0;
            for (auto pal : adj[x]) {
                for (auto palofpal : adj[pal]) {
                    if (find(adj[x].begin(), adj[x].end(), palofpal) == adj[x].end() && palofpal != x) {
                        palofpals.insert(palofpal);
                    }
                }
            }
            cout << palofpals.size() << "\n";
        } else if (c == 's') {
            int x, y; cin >> x >> y;
            int sep = bfs(x, y);
            sep == 0 ? cout << "Not connected\n" : cout << sep << "\n";
        } else if (c == 'q') {
            break;
        }
    }
}
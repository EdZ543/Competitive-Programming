#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
vector<bool> isPho(100000);
vector<int> adj[100000];
int nodesLeft;
vector<bool> visited(100000);
int farthestNode, maxCount = INT_MIN;

void bfs() {
    visited.assign(100000, false);
    queue<int> bfsQueue;

    for (int i = 0; i < n; i++) {
        if (!isPho[i] && adj[i].size() == 1) {
            visited[i] = true;
            bfsQueue.push(i);
        }
    }

    while (!bfsQueue.empty()) {
        int currentNode = bfsQueue.front();
        // cout << currentNode << "\n";
        bfsQueue.pop();
        
        for (auto u : adj[currentNode]) {
            if (!visited[u] && !isPho[u] && adj[u].size() == 2) {
                visited[u] = true;
                bfsQueue.push(u);
            }
            adj[u].erase(remove(adj[u].begin(), adj[u].end(), currentNode), adj[u].end());
        }

        nodesLeft--;
    }
}

void dfs(int v, int count) {
    visited[v] = true;
    count++;
    if (count >= maxCount) {
        maxCount = count;
        farthestNode = v;
    }
    for (auto u : adj[v]) {
        if (!visited[u]) {
            dfs(u, count);
        }
    }
}

int diameter() {
    visited.assign(100000, false);
    dfs(farthestNode, 0);
    visited.assign(100000, false);
    dfs(farthestNode, 0);
    return maxCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m; 
    nodesLeft = n;

    for (int i = 0; i < m; i++) {
        int pho; cin >> pho;
        isPho[pho] = true;
        farthestNode = pho;
    }

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs();

    // cout << diameter() << "\n";
    cout << 2*(nodesLeft-1)-(diameter()-1) << "\n";
}
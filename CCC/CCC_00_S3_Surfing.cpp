#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<int> adj[100];
vector<bool> visited(100, false);
map<string, int> urltoi;

bool dfs(int v, int target) {
    if (v == target) return true;
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) {
            if (dfs(u, target)) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        string url; cin >> url;
        urltoi.insert({url, urltoi.size()});

        while (true) {
            string line; getline(cin, line);
            if (line == "</HTML>") break;

            vector<string> matches;
            for (int i = 0; i < line.size(); i++) {
                if (line.substr(i, 9) == "<A HREF=\"") {
                    size_t end = line.find(">", i);
                    if (end != string::npos) {
                        matches.push_back(line.substr(i+9, end-i-10));
                    }
                }
            }

            for (auto match : matches) {
                cout << "Link from " << url << " to " << match << "\n";
                if (urltoi.find(match) == urltoi.end()) {
                    urltoi.insert({match, urltoi.size()}); 
                }
                adj[urltoi[url]].push_back(urltoi[match]);
            }
        }
    }

    while (true) {
        string a, b; cin >> a >> b;
        if (a == "The" && b == "End") break;
        visited.assign(100, false);
        cout << (dfs(urltoi[a], urltoi[b]) ? "Can " : "Can't ") << "surf from " << a << " to " << b << ".\n";
    }
}
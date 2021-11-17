#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

vector<ll> adj_list[3001], order(3001);
vector<bool> visited(3001), closed(3001);
ll nodes = 0;

void dfs(ll node) {
    if (visited[node] || closed[node]) return;

    nodes++;
    visited[node] = true;
    for (ll u : adj_list[node]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main(){
    setIO("closing");

    ll N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        ll a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        cin >> order[i];
    }
    dfs(1);
    cout << (nodes == N ? "YES\n" : "NO\n");
    for (int i = 0; i < N - 1; i++) {
        fill(visited.begin(), visited.end(), false);
        nodes = 0;
        closed[order[i]] = true;
        dfs(order[N-1]);
        (nodes == N-i-1) ? cout << "YES\n" : cout << "NO\n";
    }
}
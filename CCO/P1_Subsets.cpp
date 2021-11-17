#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> sets(26);
vector<int> adj[26];
vector<bool> visited(26, false);
vector<bool> appeared(26, false);

set<char> dfs(int v){
    visited[v] = true;
    set<char> ret;
    for(auto c:sets[v]) ret.insert(c);
    for(auto u:adj[v]){
        if(!visited[u]){
            set<char> next = dfs(u);
            for(auto c:next) ret.insert(c);
        }
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        char a, b; string temp; cin >> a >> temp >> b;
        int x = a-'A';
        appeared[x] = true;

        if(isupper(b)){
            adj[x].push_back(b-'A');
            appeared[b-'A'] = true;
        }else{
            sets[x].push_back(b);
        }
    }

    for(int i=0;i<26;i++){
        if(!appeared[i]) continue;
        visited.assign(26, false);
        set<char> sol = dfs(i);
        cout << (char)(i+'A') << " = {";
        int count = 0;
        for(auto c:sol){
            cout << c;
            if(count != sol.size()-1) cout << ',';
            count++;
        }
        cout << "}\n";
    }    
}
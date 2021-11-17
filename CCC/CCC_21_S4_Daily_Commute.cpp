#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, w, d; cin >> n >> w >> d;

    vector<int> al[n+1];
    int wdist[n+1];

    fill_n(wdist, n+1, 1e9);
    wdist[n] = 0;

    for(int a=0;a<w;a++){
        int from, to; cin >> from >> to;
        al[to].push_back(from);
    }

    queue<int> q;
    vector<bool> visited(n+1);

    visited[n] = true;
    q.push(n);

    while(!q.empty()){
        int curstation = q.front();
        q.pop();
        for(const int nextStation:al[curstation]){
            if(!visited[nextStation]){
                wdist[nextStation] = wdist[curstation]+1;
                visited[nextStation] = true;
                q.push(nextStation);
            }
        }
    }

    int subwayline[n+1];

    multiset<int> cdist;

    for(int a=1;a<=n;a++){
        cin >> subwayline[a];
        cdist.insert(a-1+wdist[subwayline[a]]);
    }

    for(int a=0;a<d;a++){
        int station1, station2; cin >> station1 >> station2;

        int station1OldDist = station1-1+wdist[subwayline[station1]];
        int station2OldDist = station2-1+wdist[subwayline[station2]];

        cdist.erase(cdist.find(station1OldDist));
        cdist.erase(cdist.find(station2OldDist)); 

        swap(subwayline[station1], subwayline[station2]);

        cdist.insert(station1-1+wdist[subwayline[station1]]); 
        cdist.insert(station2-1+wdist[subwayline[station2]]); 

        cout << *cdist.begin() << '\n';
    }
}
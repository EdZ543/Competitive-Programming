#include <bits/stdc++.h>
using namespace std;

using T = pair<long long, long long>;

T ask(T p){
    cout << "? "<< p.first/2 << " " << p.second/2 << endl;
    long long x, y; cin >> x >> y;
    x *= 2;
    y *= 2;
    return {x, y};
}

int main(){
    T top = ask({0, LLONG_MAX}), bottom = ask({0, -LLONG_MAX});
    long long sol = 2;
    queue<pair<T, T>> q;
    q.push({top, bottom});
    q.push({bottom, top});
    while(!q.empty()){
        T a, b; tie(a, b) = q.front(); q.pop();
        T m = {(a.first+b.first)/2, (a.second+b.second)/2};
        long long dx = b.first-a.first, dy = b.second-a.second;
        while(abs(dx) < 1e15 && abs(dy) < 1e15){
            dx *= 2;
            dy *= 2;
        }
        T c = ask({m.first-dy, m.second+dx});
        if(c != a && c != b){
            sol++;
            q.push({a, c});
            q.push({c, b});
        }
    }
    cout << "! " << sol << endl;
}
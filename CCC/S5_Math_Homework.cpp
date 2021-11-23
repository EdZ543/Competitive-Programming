#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> subs(150001);
vector<vector<int>> diff(17, vector<int>(150005, 0));
vector<int> d(150001, 1);

struct segtree{
    int size;
    vector<int> gcds;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        gcds.assign(2*size, 0);
    }

    void set(int pos, int value, int ind, int lx, int rx){
        if(rx-lx == 1){
            gcds[ind] = value;
            return;
        }
        int m = (lx+rx)/2;
        if(pos < m){
            set(pos, value, 2*ind+1, lx, m);
        }else{
            set(pos, value, 2*ind+2, m, rx);
        }
        gcds[ind] = gcd(gcds[2*ind+1], gcds[2*ind+2]);
    }

    void set(int pos, int value){
        set(pos, value, 0, 0, size);
    }

    int getgcd(int l, int r, int ind, int lx, int rx){
        if(lx >= r || rx <= l) return 0;
        if(lx >= l && rx <= r) return gcds[ind];
        int m = (lx+rx)/2;
        int gcd1 = getgcd(l, r, 2*ind+1, lx, m);
        int gcd2 = getgcd(l, r, 2*ind+2, m, rx);
        return gcd(gcd1, gcd2);
    }

    int getgcd(int l, int r){
        return getgcd(l, r, 0, 0, size);
    }
};

int main(){
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int x, y, z; cin >> x >> y >> z;
        subs[i] = {x, y, z};
        diff[z][x]++;
        diff[z][y+1]--;
    }

    segtree s;
    s.init(n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=16;j++){
            diff[j][i] += diff[j][i-1];
            if(diff[j][i] != 0) d[i] = lcm(d[i], j);
        }
        s.set(i-1, d[i]);
    }

    for(int i=0;i<m;i++){
        if(s.getgcd(subs[i][0]-1, subs[i][1]) != subs[i][2]){
            cout << "Impossible";
            return 0;
        }
    }

    for(int i=1;i<=n;i++){
        cout << d[i] << " ";
    }
}
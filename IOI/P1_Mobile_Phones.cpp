#include <bits/stdc++.h>
using namespace std;

struct bit{
    vector<vector<int>> tree;

    void init(int n){
        tree.assign(n, vector<int>(n, 0));
    }

    void add(int x, int y, int a){
        for(int r=y;r<tree.size();r+=r&-r){
            for(int c=x;c<tree.size();c+=c&-c){
                tree[r][c] += a;
            }
        }
    }

    int prefixSum(int x, int y){
        int ret = 0;
        for(int r=y;r>=1;r-=r&-r){
            for(int c=x;c>=1;c-=c&-c){
                ret += tree[r][c];
            }
        }
        return ret;
    }

    int sum(int l, int r, int b, int t){
        return prefixSum(r, t)-prefixSum(l-1, t)-prefixSum(r, b-1)+prefixSum(l-1, b-1);
    }
};

int s;

int main(){
    bit tr;
    while(true){
        int ins; cin >> ins;
        if(ins == 0){
            cin >> s;
            tr.init(s+1);
        }else if(ins == 1){
            int x, y, a; cin >> x >> y >> a;
            tr.add(x+1, y+1, a);
        }else if(ins == 2){
            int l, b, r, t; cin >> l >> b >> r >> t;
            cout << tr.sum(l+1, r+1, b+1, t+1) << "\n";
        }else if(ins == 3){
            break;
        }
    }
}
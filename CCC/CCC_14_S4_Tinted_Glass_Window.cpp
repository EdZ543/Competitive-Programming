#include <bits/stdc++.h>
using namespace std;

struct rect{
    long long lx, ty, rx, by, tint;
};

vector<rect> rects(1000);
set<long long> xs_set, ys_set;

int main(){
    long long n, t; cin >> n >> t;
    for(int i=0;i<n;i++){
        cin >> rects[i].lx >> rects[i].ty >> rects[i].rx >> rects[i].by >> rects[i].tint;
        xs_set.insert(rects[i].lx);
        xs_set.insert(rects[i].rx);
        ys_set.insert(rects[i].ty);
        ys_set.insert(rects[i].by);
    }
    vector<long long> xs(xs_set.begin(), xs_set.end()), ys(ys_set.begin(), ys_set.end());

    map<long long, long long> xindex, yindex;
    for(int i=0;i<xs.size();i++){
        xindex.insert({xs[i], i});
    }
    for(int i=0;i<ys.size();i++){
        yindex.insert({ys[i], i});
    }

    vector<vector<long long>> diff_arrs(ys.size(), vector<long long>(xs.size(), 0));
    for(int w=0;w<n;w++){
        rect r = rects[w];
        for(int i=yindex[r.ty];i<yindex[r.by];i++){
            diff_arrs[i][xindex[r.lx]] += r.tint;
            diff_arrs[i][xindex[r.rx]] -= r.tint;
        }
    }
    long long sol = 0;
    for(int i=0;i<diff_arrs.size();i++){
        for(int j=0;j<diff_arrs[i].size();j++){
            if(j < diff_arrs[i].size()-1) diff_arrs[i][j+1] = diff_arrs[i][j] + diff_arrs[i][j+1];
            if(diff_arrs[i][j] >= t){
                sol += (ys[i+1]-ys[i])*(xs[j+1]-xs[j]);
            }
        }
    }
    cout << sol;
}
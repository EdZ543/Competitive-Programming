#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<string> a(40), b(40);

vector<int> bruh(string as, string bs, vector<int> seq){
    if(seq.size() >= m) return {};
    if(as != "" && bs != "" && as == bs) return seq;
    for(int i=0;i<n;i++){
        vector<int> nseq = seq; nseq.push_back(i+1);
        vector<int> nbruh = bruh(as+a[i], bs+b[i], nseq);
        if(nbruh.size() > 0) return nbruh;
    }
    return {};
}

int main(){
    cin >> m >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    vector<int> sol = bruh("", "", {});
    if(sol.size() > 0){
        cout << sol.size() << "\n";
        for(auto x:sol) cout << x << "\n";
    }else{
        cout << "No solution.";
    }
}
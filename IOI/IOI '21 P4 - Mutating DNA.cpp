#include <bits/stdc++.h>
using namespace std;

struct State{
    int subAA = 0, subAT = 0, subAC = 0, subBA = 0, subBT = 0, subBC = 0;
    int at = 0, ac = 0, ta = 0, tc = 0, ca = 0, ct = 0;

    State(int subAA_, int subAT_, int subAC_, int subBA_, int subBT_, int subBC_, int at_, int ac_, int ta_, int tc_, int ca_, int ct_){
        subAA = subAA_;
        subAT = subAT_;
        subAC = subAC_;
        subBA = subBA_;
        subBT = subBT_;
        subBC = subBC_;
        at = at_;
        ac = ac_;
        ta = ta_;
        tc = tc_;
        ca = ca_;
        ct = ct_;
    }
};

string a, b;
vector<State> states;

void init(string a, string b){
    ::a = a;
    ::b = b;

    State state(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

    for(int i=0;i<a.size();i++){
        if(a[i] == 'A') state.subAA++;
        else if(a[i] == 'T') state.subAT++;
        else if(a[i] == 'C') state.subAC++;
        if(b[i] == 'A') state.subBA++;
        else if(b[i] == 'T') state.subBT++;
        else if(b[i] == 'C') state.subBC++;

        if(a[i] == 'A'){
            if(b[i] == 'T') state.at++;
            else if(b[i] == 'C') state.ac++;
        }else if(a[i] == 'T'){
            if(b[i] == 'A') state.ta++;
            else if(b[i] == 'C') state.tc++;
        }else if(a[i] == 'C'){
            if(b[i] == 'A') state.ca++;
            else if(b[i] == 'T') state.ct++;
        }

        states.push_back(state);
    }
}

int get_distance(int x, int y){
    int subAA = states[y].subAA;
    int subAT = states[y].subAT;
    int subAC = states[y].subAC;
    int subBA = states[y].subBA;
    int subBT = states[y].subBT;
    int subBC = states[y].subBC;

    if(x != 0){
        subAA -= states[x-1].subAA;
        subAT -= states[x-1].subAT;
        subAC -= states[x-1].subAC;
        subBA -= states[x-1].subBA;
        subBT -= states[x-1].subBT;
        subBC -= states[x-1].subBC;
    }

    if(subAA != subBA || subAT != subBT || subAC != subBC) return -1;

    int at = states[y].at;
    int ac = states[y].ac;
    int ta = states[y].ta;
    int tc = states[y].tc;
    int ca = states[y].ca;
    int ct = states[y].ct;

    if(x != 0){
        at -= states[x-1].at;
        ac -= states[x-1].ac;
        ta -= states[x-1].ta;
        tc -= states[x-1].tc;
        ca -= states[x-1].ca;
        ct -= states[x-1].ct;
    }

    int ret = 0;

    int atMin = min(at, ta);
    int acMin = min(ac, ca);
    int tcMin = min(tc, ct);

    ret += atMin; at -= atMin; ta -= atMin;
    ret += acMin; ac -= acMin; ca -= acMin;
    ret += tcMin; tc -= tcMin; ct -= tcMin;

	int triplets = at+ac+ta+tc+ca+ct;
	ret += triplets-triplets/3;

    return ret;
}

int main(){
    int n, q; cin >> n >> q;
    string a, b; cin >> a >> b;
    init(a, b);
    for(int i=0;i<q;i++){
        int x, y; cin >> x >> y;
        cout << get_distance(x, y) << '\n';
    }
}

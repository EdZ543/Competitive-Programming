#include <bits/stdc++.h>
using namespace std;

int k;

bool done(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] == '1') return false;
    }
    return true;
}

string turn(string s, int i){
    s[i] = '1';
    int length = 1;
    int l = i, r = i;
    while(s[l-1] == '1'){
        l--;
        length++;
    }
    while(s[r+1] == '1'){
        r++;
        length++;
    }
    if(length >= 4){
        for(int j=l;j<=r;j++){
            s[j] = '0';
        }
    }
    return s;
}

string next(string s){
    int l = s.find("10"), lpos, lsize;
    if(l != -1){
        lpos = l+1;
        lsize = 0;
        while(l >= 0 && s[l] == '1'){
            l--;
            lsize++;
        }
    }else{
        lpos = -1;
        lsize = INT_MAX;
    }

    int r = s.rfind("01"), rpos, rsize;
    if(r != -1){
        rpos = r;
        rsize = 0;
        r++;
        while(r < s.size() && s[r] == '1'){
            r++;
            rsize++;
        }
    }else{
        rpos = -1;
        rsize = INT_MAX;
    }

    if(lpos != -1){
        if(lsize <= rsize){
            s = turn(s, lpos);
        }else{
            s = turn(s, rpos);
        }
    }else{
        s = turn(s, rpos);
    }

    return s;
}

int main(){
    cin >> k;

    string s = "";
    for(int i=0;i<k;i++){
        int x; cin >> x;
        s += to_string(x);
    }
    
    int sol = 0;
    while(!done(s)){
        s = next(s);
        sol++;
    }
    cout << sol;
}
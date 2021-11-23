#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

int operate(string op, int a, int b){
    if(op == "+"){
        return a+b;
    }else if(op == "-"){
        return a-b;
    }else if(op == "*"){
        return a*b;
    }else if(op == "q"){
        return a/b;
    }else if(op == "r"){
        return a%b;
    }
    return 0;
}

int solve(string s){
    if(s[0] != '(') return stoi(s);

    s = s.substr(1, s.size()-2);
    vector<string> tokens(3, "");
    int token = 0; int brackets = 0;

    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            brackets++;
        }else if(s[i] == ')'){
            brackets--;
        }
        
        if(brackets == 0 && s[i] == ' '){
            token++;
        }else{
            tokens[token] += s[i];
        }
    }

    return operate(tokens[0], solve(tokens[1]), solve(tokens[2]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 10;
    while(t--){
        string s; getline(cin, s);
        cout << solve(s) << "\n";
    }
}